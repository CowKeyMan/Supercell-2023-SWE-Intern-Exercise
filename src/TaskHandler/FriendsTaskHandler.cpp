#include <nlohmann/json.hpp>
#include <unordered_map>

#include "TaskHandler/FriendsTaskHandler.h"

using namespace friend_network;
using nlohmann::json;

FriendsTaskHandler::FriendsTaskHandler(
  shared_ptr<FileLineIterator> _file_iterator, shared_ptr<UserMap> _name_to_user
):
  file_iterator(_file_iterator), name_to_user(_name_to_user) {}

enum class Task { MAKE_FRIENDS, DEL_FRIENDS, UPDATE };
const auto task_to_enum = std::unordered_map<string, Task>{
  {"make_friends", Task::MAKE_FRIENDS},
  {"del_friends", Task::DEL_FRIENDS},
  {"update", Task::UPDATE}};

auto FriendsTaskHandler::read_and_process_tasks() -> void {
  string buffer;
  while ((*file_iterator) >> buffer) {
    auto j = json::parse(buffer);
    switch (task_to_enum.at(j["type"])) {
      case Task::MAKE_FRIENDS: {
        make_friends(j["user1"], j["user2"]);
        break;
      }
      case Task::DEL_FRIENDS: {
        del_friends(j["user1"], j["user2"]);
        break;
      }
      case Task::UPDATE: {
        update_inventory(j["user"], j["timestamp"], j["values"]);
        break;
      }
    }
  }
}

auto FriendsTaskHandler::make_friends(const string &user1, const string &user2)
  -> void {
  (*name_to_user)[user1].add_friend(user2);
  (*name_to_user)[user2].add_friend(user1);
}

auto FriendsTaskHandler::del_friends(const string &user1, const string &user2)
  -> void {
  (*name_to_user)[user1].remove_friend(user2);
  (*name_to_user)[user2].remove_friend(user1);
}

auto FriendsTaskHandler::update_inventory(
  const string &user, const u64 timestamp, json &values
) -> void {
  (*name_to_user)[user].update_values_notify(values, timestamp);
}
