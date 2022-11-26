#include <memory>
#include <tuple>
#include <vector>

#include <gtest/gtest.h>

#include "User/User.h"
#include "User/User_test.h"

using std::make_shared;
using std::make_tuple;
using std::vector;
using namespace friend_network;

TEST(UserTest, ManageFriends) {
  string c_name = "C";
  auto [a, b, c] = make_tuple(User("A"), User("B"), User(c_name));

  a.add_friend("B");
  b.add_friend("A");
  a.add_friend("C");
  c.add_friend("A");

  EXPECT_EQ("A", a.get_name());
  EXPECT_EQ("B", b.get_name());

  EXPECT_EQ(a.get_friends(), set<string>({"C", "B"}));
  EXPECT_EQ(b.get_friends(), set<string>({"A"}));
  EXPECT_EQ(c.get_friends(), set<string>({"A"}));

  a.remove_friend("B");
  b.remove_friend("A");

  EXPECT_EQ(a.get_friends(), set<string>({"C"}));
  EXPECT_EQ(b.get_friends(), set<string>());
  EXPECT_EQ(c.get_friends(), set<string>({"A"}));
}

TEST(UserTest, ManageValues) {
  auto a = User("A");
  a.update_values(json({{"A", "A1"}}), 1);
  EXPECT_EQ(a.get_value_json(), json({{"A", "A1"}}));
  a.update_values(json({{"A", "A0"}, {"B", "B0"}}), 0);
  EXPECT_EQ(a.get_value_json(), json({{"A", "A1"}, {"B", "B0"}}));
}

TEST(UserTest, Broadcast) {
  auto observer = make_shared<DummyUserObserver>();
  User::broadcast_observer = observer;
  auto expected = vector<json>(
    {json(
       {{"broadcast", {"B"}},
        {"user", "A"},
        {"timestamp", 0},
        {"values", {{"B", "B0"}}}}
     ),
     json(
       {{"broadcast", {"B", "C"}},
        {"user", "A"},
        {"timestamp", 2},
        {"values", {{"A", "A2"}, {"C", "C2"}}}}
     )}
  );

  auto a = User("A");
  a.update_values_notify(json({{"A", "A1"}}), 1);
  a.add_friend("B");
  a.update_values_notify(json({{"A", "A0"}, {"B", "B0"}}), 0);
  a.add_friend("C");
  a.update_values_notify(json({{"A", "A2"}, {"C", "C2"}}), 2);

  EXPECT_EQ(expected, observer->jsons);
  User::broadcast_observer = nullptr;
}
