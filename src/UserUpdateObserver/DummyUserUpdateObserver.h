#ifndef DUMMY_USER_UPDATE_OBSERVER_H
#define DUMMY_USER_UPDATE_OBSERVER_H

/**
 * @file DummyUserUpdateObserver.h
 * @brief
 */

#include <vector>

#include "User/User.h"

using std::vector;

class DummyUserUpdateObserver: public Observer<json> {
public:
  vector<json> jsons;
  void update(const json &data) override { jsons.push_back(data); };
};

#endif
