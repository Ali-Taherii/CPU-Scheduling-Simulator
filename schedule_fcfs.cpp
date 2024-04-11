#include "schedule_fcfs.h"


void FCFS::addTask(const NonPriorityTask& task) {
    np_taskList.push_back(task);
}

void FCFS::addTask(const PriorityTask& task) {}


void FCFS::scheduleTasks(CPU& cpu) {
    while (!np_taskList.empty()) {
        NonPriorityTask currentTask = np_taskList.front();
        currentTask.setRemainingBurst(0);
        np_taskList.pop_front();
        cpu.runTask(currentTask);
    }
}