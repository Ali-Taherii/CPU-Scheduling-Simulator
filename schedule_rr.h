#pragma once

#include "scheduler.h"

class RR : public Scheduler {
private:
    int timeQuantum;

public:
    RR(int quantum); // Constructor to initialize time quantum
    void addTask(const NonPriorityTask& task) override;
    void addTask(const PriorityTask& task) override; // Override addTask to maintain sorted order
    void scheduleTasks(CPU& cpu) override;
};