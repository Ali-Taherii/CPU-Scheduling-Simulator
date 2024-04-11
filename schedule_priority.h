#pragma once

#include "scheduler.h"

class Priority : public Scheduler {
public:
    void addTask(const NonPriorityTask& task) override;
    void addTask(const PriorityTask& task) override;
    void scheduleTasks(CPU& cpu) override;
};
