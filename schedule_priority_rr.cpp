#include "schedule_priority_rr.h"

PriorityRoundRobin::PriorityRoundRobin(int quantum) : timeQuantum(quantum) {}

void PriorityRoundRobin::addTask(const NonPriorityTask& task) {}

void PriorityRoundRobin::addTask(const PriorityTask& task) {
    // Find the position to insert the task based on priority
    auto tempTask = p_taskList.begin();
    while (tempTask != p_taskList.end() && tempTask->getPriority() < task.getPriority()) {
        ++tempTask;
    }
    p_taskList.insert(tempTask, task); // Insert the task at the correct position
}

void PriorityRoundRobin::scheduleTasks(CPU& cpu) {
    while (!p_taskList.empty()) {
        PriorityTask currentTask = p_taskList.front();

        if (currentTask.getRemainingBurst() <= timeQuantum) {
            currentTask.setRemainingBurst(0);
            cpu.runTask(currentTask);
            p_taskList.pop_front();
        }

        else {

            // Decrement remaining burst time for the executed task
            int remainingBurst = currentTask.getRemainingBurst() - timeQuantum;

            // Fix the remaining burst time
            currentTask.setRemainingBurst(remainingBurst);

            // Run for the time quantum
            cpu.runTask(currentTask);
            p_taskList.pop_front();


            // Add the task back to the end of the list if it still has burst time remaining
            addTask(currentTask);
        }
    }
}