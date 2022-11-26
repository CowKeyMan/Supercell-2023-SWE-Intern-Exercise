#include "TaskHandler/UpdateTaskHandler.h"

using namespace friend_network;

UpdateTaskHandler::UpdateTaskHandler(
  shared_ptr<FileLineIterator> _line_iterator, shared_ptr<UserMap> _name_to_user
):
  line_iterator(_line_iterator), name_to_user(_name_to_user) {}

auto UpdateTaskHandler::read_and_process_tasks() -> void {
  while ((*line_iterator) >> buffer) {
    auto j = json::parse(buffer);
    (*name_to_user)[j["user"]].update_values(j["values"], j["timestamp"]);
  }
}
