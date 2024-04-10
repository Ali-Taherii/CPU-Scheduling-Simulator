#include "cpu.h"
#include <iostream>

void CPU::runTask(const Task& task) {
    std::cout << "Running task: " << task.getName()
        << " with priority: " << task.getPriority()
        << " and burst: " << task.getBurst()
        << " remaining burst: " << task.getRemainingBurst()
        << std::endl;
}
