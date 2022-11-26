#ifndef USER_H
#define USER_H

/**
 * @file User.h
 * @brief Class containing user data and functions
 */

#include <map>
#include <omp.h>
#include <set>
#include <string>

#include <nlohmann/json.hpp>

#include "Utils/ObserverPattern.h"
#include "Utils/TypeDefinitions.h"

using design_utils::Observer;
using nlohmann::json;
using std::map;
using std::set;
using std::string;

namespace friend_network {

class Value {
public:
  string value;
  u64 timestamp;
};

class User {
private:
  string name;
  set<string> friends;
  map<string, Value> values;
  omp_lock_t update_mutex_;
  omp_lock_t *update_mutex = &update_mutex_;

public:
  static shared_ptr<Observer<json>> broadcast_observer;
  User(const string &_name);
  User(User &) = delete;
  User(User &&) = delete;
  auto get_name() -> const string &;
  auto add_friend(const string &friend_name) -> void;
  auto remove_friend(const string &friend_name) -> void;
  auto get_friends() -> const set<string> &;
  auto update_values(const json &new_values, u64 timestamp) -> void;
  auto update_values_notify(const json &new_values, u64 timestamp) -> void;
  auto get_value_json() -> json;
  ~User();
};

}  // namespace friend_network

#endif
