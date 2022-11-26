#include <memory>
#include <string>

#include "User/User.h"
#include "nlohmann/json.hpp"

using std::string;

using namespace friend_network;

User::User(const string &_name): name(_name) {
  omp_init_lock(update_mutex);
};

User::~User() { omp_destroy_lock(update_mutex); };

auto User::get_name() -> const string & { return name; }

auto User::add_friend(const string &friend_name) -> void {
  friends.emplace(friend_name);
}

auto User::remove_friend(const string &friend_name) -> void {
  friends.erase(friend_name);
}

auto User::get_friends() -> const set<string> & { return friends; }

auto User::update_values(const json &new_values, u64 timestamp) -> void {
  omp_set_lock(update_mutex);
  for (auto &[key, value] : new_values.items()) {
    if (!values.contains(key) || (values.contains(key) && values[key].timestamp < timestamp)) {
      values[key] = {value, timestamp};
    }
  }
  omp_unset_lock(update_mutex);
}

shared_ptr<Observer<json>> User::broadcast_observer = nullptr;

auto User::update_values_notify(const json &new_values, u64 timestamp) -> void {
  if (friends.empty() || broadcast_observer == nullptr) {
    User::update_values(new_values, timestamp);
    return;
  }
  omp_set_lock(update_mutex);
  json broadcast_json;
  for (auto &[key, value] : new_values.items()) {
    if (!values.contains(key) || (values.contains(key) && values[key].timestamp < timestamp)) {
      values[key] = {value, timestamp};
      broadcast_json["values"][key] = value;
    }
  }
  if (!broadcast_json.empty()) {
    broadcast_json["broadcast"] = friends;
    broadcast_json["timestamp"] = timestamp;
    broadcast_json["user"] = name;
    broadcast_observer->update(broadcast_json);
  }
  omp_unset_lock(update_mutex);
}

auto User::get_value_json() -> json {
  json result;
  for (auto &[key, value] : values) { result[key] = value.value; }
  return result;
}
