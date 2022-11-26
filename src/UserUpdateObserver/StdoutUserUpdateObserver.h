#ifndef STDOUT_USER_UPDATE_OBSERVER_H
#define STDOUT_USER_UPDATE_OBSERVER_H

/**
 * @file StdoutUserUpdateObserver.h
 * @brief Observers the User updates and outputs the broadcasts to disk
 */

#include <iostream>

#include "User/User.h"
#include "Utils/ObserverPattern.h"

using std::cout;
using design_utils::Observer;

namespace friend_network {

class StdoutUserUpdateObserver: public Observer<json> {
public:
  void update(const json &data) override { cout << data << '\n'; };
};

}  // namespace friend_network

#endif
