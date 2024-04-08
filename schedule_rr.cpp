#include "schedule_rr.h"


void Scheduler::addTask(const Task& task) {
    taskQueue.push(task);
}


void RR::scheduleTasks(CPU& cpu) {
    while (!taskQueue.empty()) {
        //Execute the tasks in a round-robin fashion with a time slice of 10
        Task currentTask = taskQueue.front();
        cpu.runTask(currentTask);
        taskQueue.pop();
        if (currentTask.getBurst() > 10) {
            currentTask.setRemainingBurst(currentTask.getBurst() - 10);
            taskQueue.push(currentTask);
        }
    }
}
