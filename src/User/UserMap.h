#ifndef USER_MAP_H
#define USER_MAP_H

/**
 * @file UserMap.h
 * @brief A Map which maps user names to their users. If a user is accessed but
 * not available, they are created as a new user
 */

#include <memory>
#include <string>

#include <unordered_map>

#include "User/User.h"

using std::string;
using std::unique_ptr;
using std::unordered_map;

namespace friend_network {

class UserMap {
  unordered_map<string, unique_ptr<User>> name_to_user;

public:
  auto operator[](const string &name) -> User &;
  auto to_json() -> json;
};

}  // namespace friend_network

#endif
