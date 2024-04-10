#include "schedule_sjf.h"


void SJF::addTask(const Task& task) {
    taskList.push_back(task);
}


void SJF::scheduleTasks(CPU& cpu) {
    while (!taskList.empty()) {
        //Iterate through the queue to find the shortest job (burst time), then run it and remove it from the queue

        Task shortestJob = taskList.front();
        for (int i = 0; i < taskList.size(); i++) {
            if (shortestJob.getBurst() > taskList.front().getBurst()) {
                shortestJob = taskList.front();
                break;
            }
            taskList.push_back(taskList.front());
            taskList.pop_front();
        }
        cpu.runTask(shortestJob);
        taskList.pop_front();
        
        

        
    }
}
