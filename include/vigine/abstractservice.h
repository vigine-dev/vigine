#pragma once

class AbstractService {

public:
  virtual ~AbstractService() = 0;

protected:
  AbstractService() = default;
};
