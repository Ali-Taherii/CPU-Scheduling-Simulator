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
	t.burst = burst;

	tasks.push_back(t);
}

task pickNextTask() {
	task t = tasks[0];
	int shortest_burst = t.burst;
	for (int i = 1; i < tasks.size(); i++) {
		if(tasks[i].burst < shortest_burst) {
			t = tasks[i];
			shortest_burst = t.burst;
		}
	}
	return t;
}

void schedule() {
	task t = pickNextTask();
	while (tasks.size() != 0) {
		run(t, t.burst);
	}
	//remove task t from tasks
	tasks.erase(std::remove(tasks.begin(), tasks.end(), t), tasks.end());

}
