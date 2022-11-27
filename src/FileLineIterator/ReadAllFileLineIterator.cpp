#include "FileLineIterator/ReadAllFileLineIterator.h"

using namespace friend_network;

ReadAllFileLineIterator::ReadAllFileLineIterator(const string &filename):
  FileLineIterator(filename) {
  requests.push_back("");
  while (FileLineIterator::operator>>(requests.back())) {
    requests.push_back("");
  }
  requests.pop_back();
  reset_iterator();
}

auto ReadAllFileLineIterator::operator>>(string &output) -> bool {
  bool ret = false;
#pragma omp critical(READ_ALL_FILE_LINE_ITERATOR_READ_LINE)
  {
    if (requests_iterator != requests.end()) {
      output = *requests_iterator++;
      ret = true;
    }
  }
  return ret;
}

auto ReadAllFileLineIterator::reset_iterator() -> void {
  requests_iterator = requests.begin();
}
