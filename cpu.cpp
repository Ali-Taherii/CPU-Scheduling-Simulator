#include <iostream>

using namespace std;

#include "task.h"

// run this task for the specified time slice
void run(Task t, int slice) {
    cout << "Running task: " << t.getName() 
        << " with priority: " << t.getPriority() 
        << " and burst: " << t.getBurst() << " for " 
        << slice << " units of time" << endl;
}