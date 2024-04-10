#include "schedule_rr.h"

RR::RR(int quantum) : timeQuantum(quantum) {}


void Scheduler::addTask(const Task& task) {
    taskList.push_front(task);
}

void RR::scheduleTasks(CPU& cpu) {
    while (!taskList.empty()) {
        //Execute the tasks in a round-robin fashion with a time slice of 10
        Task currentTask = taskList.front();
        cpu.runTask(currentTask);
        taskList.pop_front();
        if (currentTask.getRemainingBurst() > timeQuantum) {
            currentTask.setRemainingBurst(currentTask.getRemainingBurst() - timeQuantum);
            taskList.push_back(currentTask);
        }
    }
}
