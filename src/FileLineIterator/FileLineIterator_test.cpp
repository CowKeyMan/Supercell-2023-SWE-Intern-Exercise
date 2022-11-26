#include <string>
#include <vector>

#include <gtest/gtest.h>
#include <type_traits>

#include "FileLineIterator/FileLineIterator.h"

using std::move;
using std::string;
using std::vector;

namespace friend_network {

TEST(FileIteratorTest, TestIterator) {
  vector<string> expected = {
    R"({ "type": "make_friends", "user1": "ab", "user2": "cd" })",
    R"({ "type": "update", "user": "ab", "timestamp": 100, "values": { "foo": "bar" }})",
    R"({ "type": "update", "user": "ab", "timestamp": 99, "values": { "foo": "bar" }})",
    R"({ "type": "update", "user": "ab", "timestamp": 100, "values": { "foo": "bar" }})",
    R"({ "type": "update", "user": "ab", "timestamp": 101, "values": { "foo": "bar" }})",
    R"({ "type": "update", "user": "ab", "timestamp": 102, "values": { "foo": "barf" }})"};
  auto fi = FileLineIterator("test_objects/ex1/input1.txt");
  vector<string> actual;
  string buffer;
  while (fi >> buffer) { actual.push_back(move(buffer)); }
  EXPECT_EQ(expected, actual);
  EXPECT_EQ(fi >> buffer, false);
}

}  // namespace friend_network
