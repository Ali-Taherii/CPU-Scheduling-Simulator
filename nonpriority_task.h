#pragma once

#include "task.h"

class NonPriorityTask : public Task {
public:
    // Constructor
    NonPriorityTask(const std::string& name, int burst);

    // Override execute method
    void execute() override;
};