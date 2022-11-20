#ifndef USER_H
#define USER_H

/**
 * @file User.h
 * @brief Class containing user data and functions
 */

#include <string>

#include <unordered_set>

using std::string;
using std::unordered_set;

namespace friend_network {

class User {
private:
  string name;
  unordered_set<string> friends;

public:
  User(string &_name);
  User(string &&_name);
  auto get_name() -> const string &;
  auto add_friend(const string &friend_name) -> void;
  auto remove_friend(const string &friend_name) -> void;
  auto get_friends() -> const unordered_set<string> &;
};

}

#endif
