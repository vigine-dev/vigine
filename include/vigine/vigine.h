#pragma once

#include <memory>

class StateMachine;

class Vigine {
public:
  Vigine();
  void run();
  StateMachine *state();

private:
  std::unique_ptr<StateMachine> _stateMachine;
};
