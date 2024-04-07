#pragma once

#include <string>

using namespace std;

struct task {
	string name;
	int priority;
	int burst;
	int remaining_burst;
};
