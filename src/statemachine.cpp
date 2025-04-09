#include <vigine/statemachine.h>

StateMachine::StateMachine()
{

}

void StateMachine::changeStateTo(std::unique_ptr<AbstractState> newState)
{
    // Call exit() on the current state if it exists
    if (_currState) 
        _currState->exit();
    
    // Update the current state
    _currState = std::move(newState);
    
    // Call enter() on the new state if it exists
    if (_currState) 
        _currState->enter();
}

AbstractState *StateMachine::currentState() const
{
    return _currState.get();
}

void StateMachine::runCurrentState()
{
    // Execute the current state's lifecycle methods
    if (_currState) {
        _currState->enter();
        _currState->update();
        _currState->exit();
    }
}

bool StateMachine::hasStatesToRun() const
{
    // Check if there is a current state to run and if it is active
    return _currState != nullptr && _currState->isActive();
}
