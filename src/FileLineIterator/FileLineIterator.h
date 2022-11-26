#ifndef FILE_LINE_ITERATOR_H
#define FILE_LINE_ITERATOR_H

/**
 * @file FileLineIterator.h
 * @brief Takes a filename as input and serves it line by line
 */

#include <string>

#include "Utils/IOUtils.h"

using io_utils::ThrowingIfstream;
using std::string;

namespace friend_network {

class FileLineIterator {
private:
  ThrowingIfstream stream;

public:
  FileLineIterator(const string &filename);
  auto operator>>(string &output) -> bool;
};

}  // namespace friend_network

#endif
