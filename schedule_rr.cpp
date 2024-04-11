#include "schedule_rr.h"

RR::RR(int quantum) : timeQuantum(quantum) {}

void RR::addTask(const NonPriorityTask& task) {
    np_taskList.push_front(task);
}

void RR::addTask(const PriorityTask& task) {}

void RR::scheduleTasks(CPU& cpu) {
    while (!np_taskList.empty()) {
        //Execute the tasks in a round-robin fashion with a time slice of 10
        NonPriorityTask currentTask = np_taskList.front();
        cpu.runTask(currentTask);
        np_taskList.pop_front();
        if (currentTask.getRemainingBurst() > timeQuantum) {
            currentTask.setRemainingBurst(currentTask.getRemainingBurst() - timeQuantum);
            np_taskList.push_back(currentTask);
        }
    }
}
