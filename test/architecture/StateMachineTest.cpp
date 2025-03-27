#include <gtest/gtest.h>

#include <vigine/vigine.h>
#include <vigine/statemachine.h>

#include <memory>

class SomeState: public AbstractState
{
public:
    ~SomeState() override{};
    
    void enter() override {
        // Test state enter logic
    }
    
    void exit() override {
        // Test state exit logic
    }
    
    void update() override {
        // Test state update logic
    }
    
    bool isActive() const override {
        return _isActive;
    }
    
    void setActive(bool active) {
        _isActive = active;
    }
    
private:
    bool _isActive = true;
};

class SomeState2: public AbstractState
{
public:
    ~SomeState2() override{};
    
    void enter() override {
        // Test state2 enter logic
    }
    
    void exit() override {
        // Test state2 exit logic
    }
    
    void update() override {
        // Test state2 update logic
    }
    
    bool isActive() const override {
        return _isActive;
    }
    
    void setActive(bool active) {
        _isActive = active;
    }
    
private:
    bool _isActive = true;
};

template <typename T>
concept MethodCheck_changeStateTo = requires(T t)
{
    t.changeStateTo(std::make_unique<SomeState>());
    { t.changeStateTo(std::make_unique<SomeState>()) } -> std::same_as<void>;
};

template <typename T>
concept MethodCheck_currentState = requires(T t)
{
    t.currentState();
    { t.currentState() } -> std::same_as<AbstractState*>;
};

template <typename T>
concept MethodCheck_runCurrentState = requires(T t)
{
    t.runCurrentState();
    { t.runCurrentState() } -> std::same_as<void>;
};

template <typename T>
concept MethodCheck_hasStatesToRun = requires(T t)
{
    t.hasStatesToRun();
    { t.hasStatesToRun() } -> std::same_as<bool>;
};

TEST(StateMachineTest, constructor_empty)
{
    std::unique_ptr<StateMachine> stateMachine;
    ASSERT_NO_THROW(stateMachine = std::make_unique<StateMachine>());
    ASSERT_NE(stateMachine, nullptr);
    ASSERT_EQ(stateMachine->currentState(), nullptr) << "Initial state should be nullptr";
}

TEST(StateMachineTest, changeStateTo_empty_void)
{
    EXPECT_TRUE(MethodCheck_changeStateTo<StateMachine>) << "StateMachine hasn't expected void changeStateTo() method";

    auto stateMachine = StateMachine();
    auto someState = std::make_unique<SomeState>();
    SomeState* rawPtrSomeState = someState.get();
    stateMachine.changeStateTo(std::move(someState));

    EXPECT_EQ(rawPtrSomeState, stateMachine.currentState()) << "StateMachine changeStateTo() method don't work correctly";
}

TEST(StateMachineTest, changeStateTo_nullptr)
{
    auto stateMachine = StateMachine();
    ASSERT_NO_THROW(stateMachine.changeStateTo(nullptr)) << "changeStateTo() should accept nullptr";
    ASSERT_EQ(stateMachine.currentState(), nullptr) << "currentState() should be nullptr after changeStateTo(nullptr)";
}

TEST(StateMachineTest, currentState_empty_AbstractState_pointer)
{
    EXPECT_TRUE(MethodCheck_currentState<StateMachine>) << "StateMachine hasn't expected void currentState() method";
    
    auto stateMachine = StateMachine();
    ASSERT_EQ(stateMachine.currentState(), nullptr) << "currentState() should be nullptr for newly created StateMachine";
}

TEST(StateMachineTest, runCurrentState_empty_void)
{
    EXPECT_TRUE(MethodCheck_runCurrentState<StateMachine>) << "StateMachine hasn't expected void runCurrentState() method";
    
    auto stateMachine = StateMachine();
    ASSERT_NO_THROW(stateMachine.runCurrentState()) << "runCurrentState() should not throw when no state is set";
    
    auto someState = std::make_unique<SomeState>();
    stateMachine.changeStateTo(std::move(someState));
    ASSERT_NO_THROW(stateMachine.runCurrentState()) << "runCurrentState() should not throw when state is set";
}

TEST(StateMachineTest, hasStatesToRun_empty_bool)
{
    EXPECT_TRUE(MethodCheck_hasStatesToRun<StateMachine>) << "StateMachine hasn't expected bool hasStatesToRun() method";
    
    auto stateMachine = StateMachine();
    EXPECT_FALSE(stateMachine.hasStatesToRun()) << "hasStatesToRun() should return false when no state is set";
    
    auto someState = std::make_unique<SomeState>();
    stateMachine.changeStateTo(std::move(someState));
    EXPECT_TRUE(stateMachine.hasStatesToRun()) << "hasStatesToRun() should return true when state is set";
    
    stateMachine.changeStateTo(nullptr);
    EXPECT_FALSE(stateMachine.hasStatesToRun()) << "hasStatesToRun() should return false after setting state to nullptr";
}

TEST(StateMachineTest, hasStatesToRun_inactive_state)
{
    auto stateMachine = StateMachine();
    
    auto someState = std::make_unique<SomeState>();
    SomeState* rawPtrSomeState = someState.get();
    stateMachine.changeStateTo(std::move(someState));
    EXPECT_TRUE(stateMachine.hasStatesToRun()) << "hasStatesToRun() should return true when state is active";
    
    rawPtrSomeState->setActive(false);
    EXPECT_FALSE(stateMachine.hasStatesToRun()) << "hasStatesToRun() should return false when state is inactive";
}

TEST(StateMachineTest, changeStateTo_multiple_states)
{
    auto stateMachine = StateMachine();
    
    auto state1 = std::make_unique<SomeState>();
    SomeState* rawPtrState1 = state1.get();
    stateMachine.changeStateTo(std::move(state1));
    EXPECT_EQ(rawPtrState1, stateMachine.currentState()) << "First state change failed";
    
    auto state2 = std::make_unique<SomeState2>();
    SomeState2* rawPtrState2 = state2.get();
    stateMachine.changeStateTo(std::move(state2));
    EXPECT_EQ(rawPtrState2, stateMachine.currentState()) << "Second state change failed";
}
