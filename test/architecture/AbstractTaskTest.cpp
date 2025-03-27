#include <gtest/gtest.h>

#include <vigine/abstracttask.h>
#include <vigine/vigine.h>
#include "concepts.h"

#include <memory>

// Concept for checking doWork method
template <typename T>
concept MethodCheck_DoWork = requires(T t)
{
    t.doWork();
    { t.doWork() } -> std::same_as<void>;
};

// Test class for AbstractTask
class TestTask : public AbstractTask {
public:
    void doWork() override {
        // Test implementation
    }
};

TEST(AbstractTaskTest, check_isAbstract)
{
    EXPECT_TRUE((IsAbstract<AbstractTask>))
        << "AbstractTask isn't an abstract";
}

TEST(AbstractTaskTest, method_destructor)
{
    EXPECT_TRUE((HasMethod_destructor<AbstractTask>))
        << "AbstractTask hasn't correct destructor";
}

TEST(AbstractTaskTest, constructor_empty)
{
    std::unique_ptr<AbstractTask> task;
    ASSERT_NO_THROW(task = std::make_unique<TestTask>());
    ASSERT_NE(task, nullptr);
}

TEST(AbstractTaskTest, doWork_empty_void)
{
    EXPECT_TRUE(MethodCheck_DoWork<AbstractTask>) << "AbstractTask hasn't expected void doWork() method";
    
    auto task = std::make_unique<TestTask>();
    ASSERT_NO_THROW(task->doWork());
}
