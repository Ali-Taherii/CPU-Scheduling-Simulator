#pragma once

#include "task.h"
#include "cpu.h"

#include <list>

class Scheduler {
protected:
    std::list<Task> taskList;

public:
    // Pure virtual functions
    virtual void addTask(const Task& task);
    virtual void scheduleTasks(CPU& cpu) = 0; 
};