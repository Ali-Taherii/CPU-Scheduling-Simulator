#include "Task.h"

// Constructor
Task::Task(const std::string& name,const int priority,const int burst)
    : name(name), priority(priority), burst(burst), remaining_burst(burst) {}

// Accessors
std::string Task::getName() const {
    return name;
}

int Task::getPriority() const {
    return priority;
}

int Task::getBurst() const {
    return burst;
}

int Task::getRemainingBurst() const {
    return remaining_burst;
}

// Modifier
void Task::setRemainingBurst(int remaining) {
    remaining_burst = remaining;
}