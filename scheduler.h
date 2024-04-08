#pragma once

#include "task.h"
#include "cpu.h"

#include <queue>

class Scheduler {
protected:
    std::queue<Task> taskQueue;

public:
    void addTask(const Task& task);
    virtual void scheduleTasks(CPU& cpu) = 0; // Pure virtual function
};
