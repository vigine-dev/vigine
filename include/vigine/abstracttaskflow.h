#pragma concept

#include "abstractstatus.h"
#include "abstracttask.h"

#include <memory>
#include <vector>

using Task = AbstractTask;
using Relation = std::pair<AbstractStatus, Task>;
using RelationContainer = std::vector<Relation>;
using TaskRelation = std::pair<Task, RelationContainer>;

class AbstractTaskFlow {
public:
    virtual ~AbstractTaskFlow() = 0;
    virtual void operator()() = 0;
    virtual void addTask(AbstractTask* task,
                       const RelationContainer &relations) = 0;

protected:
  AbstractTaskFlow() = default;
};
