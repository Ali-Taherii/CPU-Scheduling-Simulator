#pragma once

#include "task.h"
#include "cpu.h"

#include <queue>

class Scheduler {
private:
    std::queue<Task> taskQueue;

public:
    void addTask(const Task& task);
    void scheduleTasks(CPU cpu);
};