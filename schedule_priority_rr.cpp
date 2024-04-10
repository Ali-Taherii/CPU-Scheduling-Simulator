#include "schedule_priority_rr.h"

PriorityRoundRobin::PriorityRoundRobin(int quantum) : timeQuantum(quantum) {}

void PriorityRoundRobin::addTask(const Task& task) {
    // Find the position to insert the task based on priority
    auto tempTask = taskList.begin();
    while (tempTask != taskList.end() && tempTask->getPriority() < task.getPriority()) {
        ++tempTask;
    }
    taskList.insert(tempTask, task); // Insert the task at the correct position
}

void PriorityRoundRobin::scheduleTasks(CPU& cpu) {
    while (!taskList.empty()) {
        Task currentTask = taskList.front();

        if (currentTask.getRemainingBurst() <= timeQuantum) {
            cpu.runTask(currentTask);
            taskList.pop_front();
        }

        else {

            // Decrement remaining burst time for the executed task
            int remainingBurst = currentTask.getRemainingBurst() - timeQuantum;

            // Run for the time quantum
            currentTask.setRemainingBurst(timeQuantum);
            cpu.runTask(currentTask);
            taskList.pop_front();

            // Fix the remaining burst time
            currentTask.setRemainingBurst(remainingBurst);

            // Add the task back to the end of the list if it still has burst time remaining
            addTask(currentTask);
        }
    }
}