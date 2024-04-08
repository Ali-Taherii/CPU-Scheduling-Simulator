#include "schedule_sjf.h"


void Scheduler::addTask(const Task& task) {
    taskQueue.push(task);
}


void SJF::scheduleTasks(CPU& cpu) {
    while (!taskQueue.empty()) {
        //Iterate through the queue to find the shortest job (burst time), then run it and remove it from the queue

        Task shortestJob = taskQueue.front();
        for (int i = 0; i < taskQueue.size(); i++) {
            if (shortestJob.getBurst() > taskQueue.front().getBurst()) {
                shortestJob = taskQueue.front();
            }
            taskQueue.push(taskQueue.front());
            taskQueue.pop();
        }
        cpu.runTask(shortestJob);
        taskQueue.pop();
        
        

        
    }
}
