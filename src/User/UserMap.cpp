#include "User/UserMap.h"

using namespace friend_network;

auto UserMap::operator[](const string &name) -> User & {
  if (!name_to_user.contains(name)) {
    name_to_user.insert({name, User(name)});
  }
  return name_to_user.at(name);
}
