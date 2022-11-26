#include <istream>
#include <string>

#include "FileLineIterator/FileLineIterator.h"
#include "Utils/IOUtils.h"

using std::getline;
using std::string;

namespace friend_network {

FileLineIterator::FileLineIterator(const string &filename): stream(filename) {}

auto FileLineIterator::operator>>(string &output) -> bool {
  bool ret;
#pragma omp critical(FILE_LINE_ITERATOR_READ_LINE)
  ret = bool(getline(stream, output));
  return ret;
}

}  // namespace friend_network
