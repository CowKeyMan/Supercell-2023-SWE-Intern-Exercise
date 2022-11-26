#ifndef USER_TEST_H
#define USER_TEST_H

/**
 * @file User_test.h
 * @brief Collection of objects used for testing the user class
 */

#include "User/User.h"
#include <vector>

using std::vector;

class DummyUserObserver: public Observer<json> {
public:
  vector<json> jsons;
  void update(const json &data) override { jsons.push_back(data); };
};

#endif
