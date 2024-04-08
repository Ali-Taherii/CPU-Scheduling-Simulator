#pragma once

#include "task.h"

#include <queue>

class Scheduler {
private:
    std::queue<Task> taskQueue;

public:
    void addTask(const Task& task);
    void scheduleTasks();
};