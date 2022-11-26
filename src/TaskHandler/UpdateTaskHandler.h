#ifndef UPDATE_TASK_HANDLER_H
#define UPDATE_TASK_HANDLER_H

/**
 * @file UpdateTaskHandler.h
 * @brief Given a stream of data, it performs updates on the user inventories
 * (and always assumes they are updates)
 */

#include "FileLineIterator/FileLineIterator.h"
#include "User/UserMap.h"

namespace friend_network {

class UpdateTaskHandler {
  string buffer;
  shared_ptr<FileLineIterator> line_iterator;
  shared_ptr<UserMap> name_to_user;

public:
  UpdateTaskHandler(
    shared_ptr<FileLineIterator> _line_iterator,
    shared_ptr<UserMap> _name_to_user
  );
  auto read_and_process_tasks() -> void;
};

}  // namespace friend_network

#endif
