#include <string>

#include "FileIterator/FileIterator.h"
#include "Utils/IOUtils.h"

using std::getline;
using std::string;

namespace friend_network {

FileIterator::FileIterator(string &filename): stream(filename) {}
FileIterator::FileIterator(string &&filename): stream(filename) {}

auto FileIterator::operator>>(string &output) -> bool {
  return bool(getline(stream, output));
}

}
