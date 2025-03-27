#include <gtest/gtest.h>

#include <vigine/abstracttaskflow.h>
#include <vigine/vigine.h>
#include "concepts.h"

#include <memory>

class TaskTest : public AbstractTask {
public:
  ~TaskTest() override {}
};

class TaskFlowTest : public AbstractTaskFlow {
public:
  ~TaskFlowTest() override {};
};

template <typename T>
concept HasMethod_addTask = requires(T t, AbstractTask* task, const RelationContainer& relations)
{
  requires std::is_member_function_pointer_v<decltype(&T::addTask)>;
  { t.addTask(task, relations) } -> std::convertible_to<void>;
};

TEST(AbstractTaskFlowTest, check_isAbstract) {
  EXPECT_TRUE((IsAbstract<AbstractTaskFlow>))
      << "AbstractTaskFlow isn't an abstract";
}

TEST(AbstractTaskFlowTest, method_destructor) {
  EXPECT_TRUE((HasMethod_destructor<AbstractTaskFlow>))
      << "AbstractTaskFlow hasn't correct destructor";
}

TEST(AbstractTaskFlowTest, method_operatorFunctor) {
  EXPECT_TRUE((HasMethod_operatorFunctor<AbstractTaskFlow>))
      << "AbstractTaskFlow hasn't correct method 'operator()()'";
}

TEST(AbstractTaskFlowTest, method_addTask) {
  EXPECT_TRUE((HasMethod_addTask<AbstractTaskFlow>))
      << "AbstractTaskFlow hasn't correct method 'addTask'";
}
