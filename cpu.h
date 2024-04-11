#pragma once

#include "priority_task.h"
#include "nonpriority_task.h"

class CPU {
public:
    void runTask(PriorityTask& task);
    void runTask(NonPriorityTask& task);
};