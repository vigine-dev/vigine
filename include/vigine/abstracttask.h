#pragma once

class AbstractTask {

public:
  virtual ~AbstractTask() = default;

protected:
  AbstractTask() = default;

public:
  virtual void doWork() = 0;  // Using doWork() instead of do() because do is a reserved word in C++
};
