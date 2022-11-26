#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <initializer_list>
#include <nlohmann/json.hpp>
#include <unordered_map>

#include "FileLineIterator/FileLineIterator.h"
#include "TaskHandler/UpdateTaskHandler.h"
#include "User/User.h"
#include "User/UserMap.h"

using json = nlohmann::json;
using std::cout;
using std::make_shared;
using std::string;

using namespace friend_network;

#include <iostream>

auto main(int, char **argv) -> int {
  auto name_to_user = make_shared<UserMap>();
  auto input_iterator = make_shared<FileLineIterator>(argv[1]);

#pragma omp parallel
  {
    cout << omp_get_thread_num() << '\n';
    UpdateTaskHandler(input_iterator, name_to_user).read_and_process_tasks();
    cout << omp_get_thread_num() << '\n';
  }

  cout << "ERAF";

  cout << name_to_user->to_json() << '\n';

}
