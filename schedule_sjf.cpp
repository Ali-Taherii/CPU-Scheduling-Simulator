#include "schedule_sjf.h"


void SJF::addTask(const NonPriorityTask& task) {
    np_taskList.push_back(task);
}

void SJF::addTask(const PriorityTask& task) {}

void SJF::scheduleTasks(CPU& cpu) {
    while (!np_taskList.empty()) {
        //Iterate through the queue to find the shortest job (burst time), then run it and remove it from the queue

        NonPriorityTask shortestJob = np_taskList.front();
        for (int i = 0; i < np_taskList.size(); i++) {
            if (shortestJob.getBurst() > np_taskList.front().getBurst()) {
                shortestJob = np_taskList.front();
                break;
            }
            np_taskList.push_back(np_taskList.front());
            np_taskList.pop_front();
        }
        cpu.runTask(shortestJob);
        np_taskList.pop_front();
    }
}
