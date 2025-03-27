#pragma once

#include "abstractstate.h"

#include <memory>

class StateMachine
{
public:

public:
    StateMachine();
    void changeStateTo(std::unique_ptr<AbstractState> newState);
    AbstractState* currentState() const;
    void runCurrentState();
    bool hasStatesToRun() const;

private:
    std::unique_ptr<AbstractState> _currState;
};


