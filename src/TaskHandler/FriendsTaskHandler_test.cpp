#include <memory>

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include "FileLineIterator/FileLineIterator.h"
#include "TaskHandler/FriendsTaskHandler.h"
#include "User/User.h"
#include "User/UserMap.h"
#include "UserUpdateObserver/DummyUserUpdateObserver.h"

using namespace friend_network;
using nlohmann::json;
using std::make_shared;

void friends_task_handler_test(
  const string &input_file, const string &output_file
) {
  auto name_to_user = make_shared<UserMap>();
  auto input_iterator = make_shared<FileLineIterator>(input_file);
  auto output_iterator = make_shared<FileLineIterator>(output_file);
  auto user_observer = make_shared<DummyUserUpdateObserver>();
  User::broadcast_observer = user_observer;

  FriendsTaskHandler(input_iterator, name_to_user).read_and_process_tasks();

  vector<json> expected;
  string buffer;
  while ((*output_iterator) >> buffer) {
    expected.push_back(json::parse(buffer));
  }

  ASSERT_EQ(expected, user_observer->jsons);
}

TEST(FriendsTaskHandler, Test1) {
  friends_task_handler_test(
    "test_objects/ex1/input1.txt", "test_objects/ex1/output1.txt"
  );
}

TEST(FriendsTaskHandler, Test2) {
  friends_task_handler_test(
    "test_objects/ex1/input2.txt", "test_objects/ex1/output2.txt"
  );
}

TEST(FriendsTaskHandler, Test3) {
  friends_task_handler_test(
    "test_objects/ex1/input3.txt", "test_objects/ex1/output3.txt"
  );
}
