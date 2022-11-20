#ifndef FILE_ITERATOR_H
#define FILE_ITERATOR_H

/**
 * @file FileIterator.h
 * @brief Takes a filename as input and serves it line by line
 */

#include <string>

#include "Utils/IOUtils.h"

using io_utils::ThrowingIfstream;
using std::string;

namespace friend_network {

class FileIterator {
private:
  ThrowingIfstream stream;

public:
  FileIterator(string &filename);
  FileIterator(string &&filename);
  auto operator>>(string &output) -> bool;
};

}

#endif
