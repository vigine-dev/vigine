#include <gtest/gtest.h>

#include <vigine/abstractstate.h>
#include <vigine/abstracttask.h>
#include "concepts.h"

#include <memory>

// Concepts for checking AbstractState methods
template <typename T>
concept MethodCheck_Enter = requires(T t)
{
    t.enter();
    { t.enter() } -> std::same_as<void>;
};

template <typename T>
concept MethodCheck_Exit = requires(T t)
{
    t.exit();
    { t.exit() } -> std::same_as<void>;
};

template <typename T>
concept MethodCheck_Update = requires(T t)
{
    t.update();
    { t.update() } -> std::same_as<void>;
};

template <typename T>
concept MethodCheck_AddTask = requires(T t)
{
    t.addTask(std::make_unique<AbstractTask>());
    { t.addTask(std::make_unique<AbstractTask>()) } -> std::same_as<void>;
};

template <typename T>
concept MethodCheck_ClearTasks = requires(T t)
{
    t.clearTasks();
    { t.clearTasks() } -> std::same_as<void>;
};

template <typename T>
concept MethodCheck_RemoveTask = requires(T t)
{
    t.removeTask(nullptr);
    { t.removeTask(nullptr) } -> std::same_as<bool>;
};

template <typename T>
concept MethodCheck_IsActive = requires(T t)
{
    t.isActive();
    { t.isActive() } -> std::same_as<bool>;
};

template <typename T>
concept MethodCheck_SetActive = requires(T t)
{
    t.setActive(true);
    { t.setActive(true) } -> std::same_as<void>;
};

// Test class for AbstractTask
class TestTask : public AbstractTask {
public:
    void doWork() override {
        // Test implementation
    }
};

// Test class for AbstractState
class TestState : public AbstractState {
public:
    void enter() override {}
    void exit() override {}
};

TEST(AbstractStateTest, check_isAbstract)
{
    EXPECT_TRUE((IsAbstract<AbstractState>))
        << "AbstractState isn't an abstract";
}

TEST(AbstractStateTest, method_destructor)
{
    EXPECT_TRUE((HasMethod_destructor<AbstractState>))
        << "AbstractState hasn't correct destructor";
}

TEST(AbstractStateTest, constructor_empty)
{
    std::unique_ptr<AbstractState> state;
    ASSERT_NO_THROW(state = std::make_unique<TestState>());
    ASSERT_NE(state, nullptr);
}

TEST(AbstractStateTest, enter_empty_void)
{
    EXPECT_TRUE(MethodCheck_Enter<AbstractState>) << "AbstractState hasn't expected void enter() method";
}

TEST(AbstractStateTest, exit_empty_void)
{
    EXPECT_TRUE(MethodCheck_Exit<AbstractState>) << "AbstractState hasn't expected void exit() method";
}

TEST(AbstractStateTest, update_empty_void)
{
    EXPECT_TRUE(MethodCheck_Update<AbstractState>) << "AbstractState hasn't expected void update() method";
}

TEST(AbstractStateTest, addTask_empty_void)
{
    EXPECT_TRUE(MethodCheck_AddTask<AbstractState>) << "AbstractState hasn't expected void addTask() method";
}

TEST(AbstractStateTest, clearTasks_empty_void)
{
    EXPECT_TRUE(MethodCheck_ClearTasks<AbstractState>) << "AbstractState hasn't expected void clearTasks() method";
}

TEST(AbstractStateTest, removeTask_empty_bool)
{
    EXPECT_TRUE(MethodCheck_RemoveTask<AbstractState>) << "AbstractState hasn't expected bool removeTask() method";
}

TEST(AbstractStateTest, isActive_empty_bool)
{
    EXPECT_TRUE(MethodCheck_IsActive<AbstractState>) << "AbstractState hasn't expected bool isActive() method";
}

TEST(AbstractStateTest, setActive_empty_void)
{
    EXPECT_TRUE(MethodCheck_SetActive<AbstractState>) << "AbstractState hasn't expected void setActive() method";
}

TEST(AbstractStateTest, task_management)
{
    auto state = std::make_unique<TestState>();
    
    // Test adding a task
    auto task = std::make_unique<TestTask>();
    AbstractTask* taskPtr = task.get();
    ASSERT_NO_THROW(state->addTask(std::move(task)));
    
    // Test removing a task
    EXPECT_TRUE(state->removeTask(taskPtr));
    
    // Test removing a non-existent task
    EXPECT_FALSE(state->removeTask(nullptr));
    
    // Test clearing all tasks
    ASSERT_NO_THROW(state->clearTasks());
}

TEST(AbstractStateTest, active_state_management)
{
    auto state = std::make_unique<TestState>();
    
    // Test initial state (should be active by default)
    EXPECT_TRUE(state->isActive()) << "New state should be active by default";
    
    // Test setting state to inactive
    state->setActive(false);
    EXPECT_FALSE(state->isActive()) << "State should be inactive after setActive(false)";
    
    // Test setting state back to active
    state->setActive(true);
    EXPECT_TRUE(state->isActive()) << "State should be active after setActive(true)";
} 