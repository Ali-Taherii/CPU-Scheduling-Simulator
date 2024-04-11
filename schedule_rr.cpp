#include "schedule_rr.h"

RR::RR(int quantum) : timeQuantum(quantum) {}

void RR::addTask(const NonPriorityTask& task) {}

void RR::addTask(const PriorityTask& task) {
    p_taskList.push_front(task);
}

void RR::scheduleTasks(CPU& cpu) {
    while (!p_taskList.empty()) {
        //Execute the tasks in a round-robin fashion with a time slice of 10
        PriorityTask currentTask = p_taskList.front();
        cpu.runTask(currentTask);
        p_taskList.pop_front();
        if (currentTask.getRemainingBurst() > timeQuantum) {
            currentTask.setRemainingBurst(currentTask.getRemainingBurst() - timeQuantum);
            p_taskList.push_back(currentTask);
        }
    }
}
