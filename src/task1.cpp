#include "FileLineIterator/FileLineIterator.h"
#include "TaskHandler/FriendsTaskHandler.h"
#include "User/UserMap.h"
#include "UserUpdateObserver/StdoutUserUpdateObserver.h"

using json = nlohmann::json;
using std::cerr;
using std::make_shared;
using std::string;

using namespace friend_network;

#include <iostream>

auto main(int, char **argv) -> int {
  if (string(argv[1]) != "-i") {
    cerr << "first argument should be '-i' follwed by the filename in the "
            "second argument\n";
    exit(1);
  }
  auto name_to_user = make_shared<UserMap>();
  auto input_iterator = make_shared<FileLineIterator>(argv[2]);
  auto user_observer = make_shared<StdoutUserUpdateObserver>();
  User::broadcast_observer = user_observer;

  FriendsTaskHandler(input_iterator, name_to_user).read_and_process_tasks();
}
