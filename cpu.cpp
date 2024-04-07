#include <iostream>

using namespace std;

#include "task.h"

// run this task for the specified time slice
void run(task t, int slice) {
    cout << "Running task: " << t.name << " with priority: " << t.priority << " and burst: " << t.burst << " for " << slice << " units of time" << endl;
}