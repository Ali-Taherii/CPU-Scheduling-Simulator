#include "nonpriority_task.h"

#include <iostream>


// NonPriorityTask class implementation
NonPriorityTask::NonPriorityTask(const std::string& name, int burst) 
    : Task(name, burst) {}

void NonPriorityTask::execute() {
    std::cout << "Running task: " << name
        << " and burst: " << burst
        << std::endl;
}