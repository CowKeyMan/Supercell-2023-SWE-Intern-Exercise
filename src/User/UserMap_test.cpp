#include <gtest/gtest.h>

#include "User/UserMap.h"

using namespace friend_network;

TEST(UserMapTest, ToJson) {
  auto host = UserMap();
  host["A"].update_values(json({{"A", "A1"}}), 0);
  host["B"].update_values(json({{"B", "B1"}}), 0);
  auto expected = json({{"A", {{"A", "A1"}}}, {"B", {{"B", "B1"}}}});
  EXPECT_EQ(expected, host.to_json());
}
