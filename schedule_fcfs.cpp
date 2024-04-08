#include "schedule_fcfs.h"


void Scheduler::addTask(const Task& task) {
    taskList.push_back(task);
}


void FCFS::scheduleTasks(CPU& cpu) {
    while (!taskList.empty()) {
        Task currentTask = taskList.front();
        taskList.pop_front();
        cpu.runTask(currentTask);
    }
}