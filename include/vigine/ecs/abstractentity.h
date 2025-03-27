#pragma once

#include <string>
#include <vector>

class AbstractComponent;

class AbstractEntity {
public:
  virtual ~AbstractEntity() = 0;

  virtual void addComponent(AbstractComponent* component) = 0;
  virtual void removeComponent(AbstractComponent* component) = 0;
  virtual AbstractComponent* getComponent(const std::string& type) = 0;
  virtual bool hasComponent(const std::string& type) = 0;
  virtual std::vector<AbstractComponent*> getAllComponents() const = 0;

protected:
  AbstractEntity() = default;
}; 