#include <iostream>
#include <memory>
#include <sstream>

#include <gtest/gtest.h>

using std::cout;
using std::make_shared;
using std::streambuf;
using std::stringstream;

#include "User/User.h"
#include "UserUpdateObserver/StdoutUserUpdateObserver.h"

using namespace friend_network;

TEST(StdoutUserUpdateObserverTest, ToStdout) {
  // redirect output to buffer
  stringstream buffer;
  streambuf *sbuf = std::cout.rdbuf();
  cout.rdbuf(buffer.rdbuf());

  auto host = make_shared<StdoutUserUpdateObserver>();
  User::broadcast_observer = host;

  auto user = User("A");
  user.add_friend("B");
  user.update_values_notify({{"A", "A0"}, {"B", "B0"}}, 0);

  EXPECT_EQ(
    json::parse(buffer.str()),
    json(
      {{"broadcast", {"B"}},
       {"timestamp", 0},
       {"user", "A"},
       {"values", {{"A", "A0"}, {"B", "B0"}}}}
    )
  );

  // reset stdout
  std::cout.rdbuf(sbuf);
}
