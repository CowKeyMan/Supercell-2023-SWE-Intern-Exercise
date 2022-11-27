#include <chrono>
#include <iostream>

#include <fmt/core.h>

#include "FileLineIterator/ReadAllFileLineIterator.h"
#include "TaskHandler/UpdateTaskHandler.h"
#include "User/UserMap.h"

using fmt::format;
using std::cout;
using std::make_shared;
using std::string;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

using namespace friend_network;

#include <iostream>

auto main(int, char **argv) -> int {
  auto input_iterator
    = make_shared<ReadAllFileLineIterator>(argv[1]);
  auto name_to_user = make_shared<UserMap>();

  int max_threads;
#pragma omp parallel
#pragma omp single
  max_threads = omp_get_num_threads();

  cout << "Run,Threads,Time\n";
  for (int i = 1; i <= 5; ++i) {
    for (int t = 1; t <= max_threads; ++t) {
      auto start = high_resolution_clock::now();
#pragma omp parallel num_threads(t)
      {
        UpdateTaskHandler(input_iterator, name_to_user)
          .read_and_process_tasks();
      }
      auto end = high_resolution_clock::now();
      auto total = duration_cast<milliseconds>(end - start).count();
      cout << format("{},{},{}\n", i, t, total);
      name_to_user = make_shared<UserMap>();

      input_iterator->reset_iterator();
    }
  }
}
