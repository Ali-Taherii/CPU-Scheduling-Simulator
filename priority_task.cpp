#include "priority_task.h"

#include <iostream>

PriorityTask::PriorityTask(const std::string& name, int priority, int burst)
    : Task(name, burst), priority(priority) {}

// Accessor
int PriorityTask::getPriority() const{
    return priority;
}

void PriorityTask::execute() {
    std::cout << "Running task: " << name
        << " with priority: " << priority
        << " and burst: " << burst
        << " remaining burst: " << remaining_burst
        << std::endl;
}