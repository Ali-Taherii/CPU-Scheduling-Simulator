#pragma once

#include "priority_task.h"
#include "nonpriority_task.h"
#include "cpu.h"

#include <list>

class Scheduler {
protected:
    std::list<PriorityTask> p_taskList;
    std::list<NonPriorityTask> np_taskList;

public:
    // Pure virtual functions
    virtual void addTask(const PriorityTask& task) = 0;
    virtual void addTask(const NonPriorityTask& task) = 0;
    virtual void scheduleTasks(CPU& cpu) = 0;
};