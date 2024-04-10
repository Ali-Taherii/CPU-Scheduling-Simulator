#pragma once

#include "scheduler.h"

class SJF : public Scheduler {
public:
    void scheduleTasks(CPU& cpu) override;
    void addTask(const Task& task) override;
};