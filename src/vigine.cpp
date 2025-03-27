#include "vigine/vigine.h"

#include "vigine/statemachine.h"

#include <iostream>
#include <thread>
#include <chrono>

Vigine::Vigine() : _stateMachine{std::make_unique<StateMachine>()} {}

void Vigine::run() { 
    // Run the current state in a loop while there are states to run
    while (state()->hasStatesToRun()) {
        // Run the current state
        state()->runCurrentState();
        
        // Make the state inactive after execution
        if (state()->currentState()) {
            state()->currentState()->setActive(false);
        }
        
        // Add a small delay to prevent CPU overload
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60 FPS
    }
}

StateMachine *Vigine::state() {
  return dynamic_cast<StateMachine *>(_stateMachine.get());
}

void exampleFunction() {}
