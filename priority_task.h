#pragma once

#include "task.h"

class PriorityTask : public Task {
private:
    int priority;

public:
    // Constructor
    PriorityTask(const std::string& name, int priority, int burst);

    // Accessor
    int getPriority() const;

    // Override execute method
    void execute() override;
};
