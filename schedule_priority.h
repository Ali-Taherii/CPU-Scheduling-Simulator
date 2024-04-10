#pragma once

#include "scheduler.h"

class Priority : public Scheduler {
public:
    void addTask(const Task& task) override;
    void scheduleTasks(CPU& cpu) override;
};
