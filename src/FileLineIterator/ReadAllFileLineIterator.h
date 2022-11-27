#ifndef READ_ALL_FILE_LINE_ITERATOR_H
#define READ_ALL_FILE_LINE_ITERATOR_H

/**
 * @file ReadAllFileLineIterator.h
 * @brief Similar to FileLineIterator but it reads the entire file first, loads
 * it into memory, then serves it. Useful for benchamrking to avoid any IO since
 * this may be variable.
 */

#include <string>
#include <vector>

#include "FileLineIterator/FileLineIterator.h"

using std::string;
using std::vector;

namespace friend_network {

class ReadAllFileLineIterator: public FileLineIterator {
private:
  vector<string> requests;
  vector<string>::iterator requests_iterator;

public:
  ReadAllFileLineIterator(const string &filename);
  auto operator>>(string &output) -> bool override;
  auto reset_iterator() -> void;
};

}  // namespace friend_network

#endif
