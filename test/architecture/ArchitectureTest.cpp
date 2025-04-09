#include <gtest/gtest.h>

#include <vigine/abstractstate.h>
#include <vigine/statemachine.h>
#include <vigine/component/componentmanager.h>
#include <vigine/entity.h>
#include <vigine/vigine.h>

#include <functional>

class OpenState : public AbstractState {
public:
    ~OpenState() override {}
    
    void enter() override {
        // Open state entry logic
    }
    
    void exit() override {
        // Open state exit logic
    }
    
    void update() override {
        // Open state update logic
        AbstractState::update(); // Call parent update to execute tasks
    }
};

class WorkState : public AbstractState {
public:
    void enter() override {
        // Work state entry logic
    }
    
    void exit() override {
        // Work state exit logic
    }
    
    void update() override {
        // Work state update logic
        AbstractState::update(); // Call parent update to execute tasks
    }
};

class ErrorState : public AbstractState {
public:
    void enter() override {
        // Error state entry logic
    }
    
    void exit() override {
        // Error state exit logic
    }
    
    void update() override {
        // Error state update logic
        AbstractState::update(); // Call parent update to execute tasks
    }
};

class CloseState : public AbstractState {
public:
    void enter() override {
        // Close state entry logic
    }
    
    void exit() override {
        // Close state exit logic
    }
    
    void update() override {
        // Close state update logic
        AbstractState::update(); // Call parent update to execute tasks
    }
};

TEST(ArchitectureTest, Vigine_run_void) {
  Vigine vigine;
  StateMachine* stateMch = vigine.state();

  stateMch->changeStateTo(std::make_unique<OpenState>());
  vigine.run();
}
