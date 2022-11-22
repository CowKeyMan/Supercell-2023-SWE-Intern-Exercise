#ifndef OBSERVER_PATTERN_H
#define OBSERVER_PATTERN_H

/**
 * @file ObserverPattern.h
 * @brief Base classes for Observer and Subject to use when using the observer
 * pattern
 */

#include <memory>

#include <unordered_set>

using std::shared_ptr;
using std::unordered_set;

namespace design_utils {

template <class T>
class Observer {
public:
  virtual void update(const T &data) = 0;
};

template <class T>
class Subject {
  unordered_set<shared_ptr<Observer<T>>> observers;

public:
  void attach(shared_ptr<Observer<T>> observer) { observers.emplace(observer); }
  void detach(shared_ptr<Observer<T>> observer) { observers.erase(observer); }
  void notify_observers(T &data) {
    for (auto &observer : observers) { update(data); }
  }
};

}  // namespace design_utils

#endif
