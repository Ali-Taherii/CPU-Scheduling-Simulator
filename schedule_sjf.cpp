#include "schedule_sjf.h"


void SJF::addTask(const NonPriorityTask& task) {
    np_taskList.push_back(task);
}

void SJF::addTask(const PriorityTask& task) {}

void SJF::scheduleTasks(CPU& cpu) {
    while (!np_taskList.empty()) {
        //Execute the tasks in a shortest job first fashion
        NonPriorityTask currentTask = np_taskList.front();
        auto it = np_taskList.begin();
        for (auto i = np_taskList.begin(); i != np_taskList.end(); i++) {
			if (i->getBurst() < currentTask.getBurst()) {
				currentTask = *i;
				it = i;
			}
		}
        cpu.runTask(currentTask);
		np_taskList.erase(it);
	}

        
}
