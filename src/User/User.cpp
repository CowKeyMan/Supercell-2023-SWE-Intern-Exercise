#include <memory>
#include <string>

#include "User/User.h"

using std::string;

using namespace friend_network;

User::User(string &_name): name(_name){};
User::User(string &&_name): name(_name){};

auto User::get_name() -> const string & { return name; }

auto User::add_friend(const string &friend_name) -> void {
  friends.emplace(friend_name);
}

auto User::remove_friend(const string &friend_name) -> void {
  friends.erase(friend_name);
}

auto User::get_friends() -> const unordered_set<string> & { return friends; }
