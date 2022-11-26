#include <memory>
#include <utility>
#include "User/UserMap.h"

using namespace friend_network;
using std::make_unique;

auto UserMap::operator[](const string &name) -> User & {
#pragma omp critical
  {
    if (!name_to_user.contains(name)) {
      name_to_user.emplace(name, make_unique<User>(name));
    }
  }
  return *name_to_user.at(name);
}

auto UserMap::to_json() -> json {
  json j;
  for (auto &[key, value] : name_to_user) { j[key] = value->get_value_json(); }
  return j;
}
