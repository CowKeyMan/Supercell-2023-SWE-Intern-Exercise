#include <fstream>
#include <memory>

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include "FileLineIterator/FileLineIterator.h"
#include "TaskHandler/UpdateTaskHandler.h"
#include "User/User.h"
#include "User/UserMap.h"

using namespace friend_network;
using nlohmann::json;
using std::ifstream;
using std::make_shared;

void update_task_handler_test(
  const string &input_file, const string &output_file
) {
  auto name_to_user = make_shared<UserMap>();
  auto input_iterator = make_shared<FileLineIterator>(input_file);

  UpdateTaskHandler(input_iterator, name_to_user).read_and_process_tasks();

  auto output_ifstream = ifstream(output_file);
  ASSERT_EQ(json::parse(output_ifstream), name_to_user->to_json());
}

TEST(UpdateTaskHandler, Test1) {
  update_task_handler_test("test_objects/ex2/input1.txt", "test_objects/ex2/output1.txt");
}
