#pragma once

#include "scheduler.h"

class Priority : public Scheduler {
public:
    void addTask(const Task& task);
    void scheduleTasks(CPU& cpu) override;
};
