#ifndef FRIENDS_TASK_HANDLER_H
#define FRIENDS_TASK_HANDLER_H

/**
 * @file FriendsTaskHandler.h
 * @brief Reads jsons and delegates tasks to the other components to make
 * friends, delete friends or update the users inventory
 */

#include <memory>

#include <unordered_map>

#include "FileLineIterator/FileLineIterator.h"
#include "User/User.h"
#include "User/UserMap.h"
#include "Utils/TypeDefinitions.h"

using std::shared_ptr;
using std::string;

namespace friend_network {

class FriendsTaskHandler {
private:
  shared_ptr<FileLineIterator> file_iterator;
  shared_ptr<UserMap> name_to_user;

public:
  FriendsTaskHandler(
    shared_ptr<FileLineIterator> _file_iterator,
    shared_ptr<UserMap> _name_to_user
  );
  auto read_and_process_tasks() -> void;

private:
  auto make_friends(const string &user1, const string &user2) -> void;
  auto del_friends(const string &user1, const string &user2) -> void;
  auto update_inventory(const string &user, const u64 timestamp, json &values)
    -> void;
};

}  // namespace friend_network

#endif
