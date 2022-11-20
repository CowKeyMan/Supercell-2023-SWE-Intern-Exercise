
#include <tuple>

#include <gtest/gtest.h>

#include "User/User.h"

using std::make_tuple;
using namespace friend_network;

TEST(UserTest, TestAll) {
  string c_name = "C";
  auto [a, b, c] = make_tuple(User("A"), User("B"), User(c_name));

  a.add_friend("B");
  b.add_friend("A");
  a.add_friend("C");
  c.add_friend("A");

  EXPECT_EQ("A", a.get_name());
  EXPECT_EQ("B", b.get_name());

  EXPECT_EQ(a.get_friends(), unordered_set<string>({"B", "C"}));
  EXPECT_EQ(b.get_friends(), unordered_set<string>({"A"}));
  EXPECT_EQ(c.get_friends(), unordered_set<string>({"A"}));

  a.remove_friend("B");
  b.remove_friend("A");


  EXPECT_EQ(a.get_friends(), unordered_set<string>({"C"}));
  EXPECT_EQ(b.get_friends(), unordered_set<string>());
  EXPECT_EQ(c.get_friends(), unordered_set<string>({"A"}));
}
