#include <iostream>

#include "scheduler.h"
#include "task.h"
#include "cpu.h"
#include <vector>

vector<task> tasks;

void add(string name, int priority, int burst) {
	task t;
	t.name = name;
	t.priority = priority;
	t.burst = t.remaining_burst = burst;

	tasks.push_back(t);
}

task pickNextTask() {
	//pick next task in a round-robin fashion
    task t = tasks[0];
	tasks.erase(tasks.begin());
	tasks.push_back(t);
	return t;
}

void schedule() {
	while (tasks.size() != 0) {
		task t = pickNextTask();

		//run task t for 10 time units
		run(t, 10);

		t.remaining_burst -= 10;
		if (t.remaining_burst <= 0) {
			//remove task t from tasks
			tasks.erase(std::remove(tasks.begin(), tasks.end(), t), tasks.end());
		}
	}
}
