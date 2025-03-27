#pragma once

#include "abstracttask.h"
#include <vector>
#include <memory>
#include <algorithm>

class AbstractState {

public:
    virtual ~AbstractState() = default;
    
    // State lifecycle methods
    virtual void enter() = 0;
    virtual void exit() = 0;
    virtual void update() {
        // By default, execute all tasks
        for (const auto& task : _tasks) {
            task->doWork();
        }
    }
    virtual bool isActive() const { return _isActive; } // By default, state is active
    virtual void setActive(bool active) { _isActive = active; }

    // Task management methods
    virtual void addTask(std::unique_ptr<AbstractTask> task) {
        _tasks.push_back(std::move(task));
    }

    virtual void clearTasks() {
        _tasks.clear();
    }

    virtual bool removeTask(AbstractTask* taskPtr) {
        auto it = std::find_if(_tasks.begin(), _tasks.end(),
            [taskPtr](const auto& task) { return task.get() == taskPtr; });
        
        if (it != _tasks.end()) {
            _tasks.erase(it);
            return true;
        }
        return false;
    }

protected:
    AbstractState() = default;
    std::vector<std::unique_ptr<AbstractTask>> _tasks;
    bool _isActive = true;
};
