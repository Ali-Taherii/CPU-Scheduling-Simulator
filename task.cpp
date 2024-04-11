#include "task.h"

// Constructor
Task::Task(const std::string& name, int burst)
    : name(name), burst(burst), remaining_burst(burst) {}

// Accessors
std::string Task::getName() const {
    return name;
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