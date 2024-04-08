#include "schedule_priority.h"


void Priority::addTask(const Task& task) {
    // Find the position to insert the task based on priority
    auto tempTask = taskList.begin();
    while (tempTask != taskList.end() && tempTask->getPriority() < task.getPriority()) {
        ++tempTask;
    }
    taskList.insert(tempTask, task); // Insert the task at the correct position
}

void Priority::scheduleTasks(CPU& cpu) {
    while (!taskList.empty()) {
        Task currentTask = taskList.front();
        cpu.runTask(currentTask);
        taskList.pop_front();
    }
}