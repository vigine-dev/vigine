#pragma once

class AbstractComponent {
public:
  virtual ~AbstractComponent() = 0;

protected:
  AbstractComponent() = default;
};
