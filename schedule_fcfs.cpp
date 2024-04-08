#include "scheduler.h"
#include "cpu.h"
#include <iostream>

void Scheduler::addTask(const Task& task) {
    taskQueue.push(task);
}

void Scheduler::scheduleTasks(CPU cpu) {
    while (!taskQueue.empty()) {
        Task currentTask = taskQueue.front();
        taskQueue.pop();

        cpu.runTask(currentTask);
    }
}
