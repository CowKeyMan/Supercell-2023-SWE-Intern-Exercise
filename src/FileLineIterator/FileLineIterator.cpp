#include <istream>
#include <string>

#include "FileLineIterator/FileLineIterator.h"
#include "Utils/IOUtils.h"

using std::getline;
using std::string;

namespace friend_network {

FileLineIterator::FileLineIterator(const string &filename): stream(filename) {}

auto FileLineIterator::operator>>(string &output) -> bool {
  return bool(getline(stream, output));
}

}  // namespace friend_network
