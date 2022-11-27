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
protected:
  ThrowingIfstream stream;

public:
  FileLineIterator(const string &filename);
  virtual auto operator>>(string &output) -> bool;
  virtual ~FileLineIterator() = default;
};

}  // namespace friend_network

#endif
