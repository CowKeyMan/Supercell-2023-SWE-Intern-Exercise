#ifndef USER_MAP_H
#define USER_MAP_H

/**
 * @file UserMap.h
 * @brief A Map which maps user names to their users. If a user is accessed but
 * not available, they are created as a new user
 */

#include <string>

#include <unordered_map>

#include "User/User.h"

using std::string;
using std::unordered_map;

namespace friend_network {

class UserMap {
  unordered_map<string, User> name_to_user;

public:
  auto operator[](const string &name) -> User &;
};

}  // namespace friend_network

#endif
