#include "schedule_fcfs.h"


void Scheduler::addTask(const Task& task){
    taskQueue.push(task);
}


void FCFS::scheduleTasks(CPU& cpu) {
    while (!taskQueue.empty()) {
        Task currentTask = taskQueue.front();
        taskQueue.pop();
        cpu.runTask(currentTask);
    }
}

