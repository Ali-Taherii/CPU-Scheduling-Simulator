#include "schedule_priority.h"

void Priority::addTask(const NonPriorityTask& task) {}

void Priority::addTask(const PriorityTask& task) {
    // Find the position to insert the task based on priority
    auto tempTask = p_taskList.begin();
    while (tempTask != p_taskList.end() && tempTask->getPriority() < task.getPriority()) {
        ++tempTask;
    }
    p_taskList.insert(tempTask, task); // Insert the task at the correct position
}

void Priority::scheduleTasks(CPU& cpu) {
    while (!p_taskList.empty()) {
        PriorityTask currentTask = p_taskList.front();
        currentTask.setRemainingBurst(0);
        cpu.runTask(currentTask);
        p_taskList.pop_front();
    }
}