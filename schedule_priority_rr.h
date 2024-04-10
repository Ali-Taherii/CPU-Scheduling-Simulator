#pragma once

#include "scheduler.h"

class PriorityRoundRobin : public Scheduler {
private:
    int timeQuantum; // Time quantum for round-robin scheduling

public:
    PriorityRoundRobin(int quantum); // Constructor to initialize time quantum
    void addTask(const Task& task) override; // Override addTask to maintain sorted order
    void scheduleTasks(CPU& cpu) override;
};