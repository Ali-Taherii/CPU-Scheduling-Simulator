#pragma once
#include <string>
using namespace std;

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10


void add(string name, int priority, int burst);


void schedule();