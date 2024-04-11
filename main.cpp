#include "priority_task.h"
#include "nonpriority_task.h"
#include "schedule_rr.h"
#include "schedule_sjf.h"
#include "cpu.h"

#include <iostream>

int main() {
    // Create tasks
    NonPriorityTask task1("Task1", 10);
    NonPriorityTask task2("Task2", 5);
    NonPriorityTask task3("Task3", 8);
    NonPriorityTask task4("Task4", 5);
    NonPriorityTask task5("Task5", 20);
    NonPriorityTask task6("Task6", 12);

    // Create a CPU
    CPU cpu;

    // Create a RR scheduler
    RR RR_Scheduler(10);
    // Create a SJF scheduler
    SJF ShortestJob;

    // Add tasks to the RR Scheduler
    RR_Scheduler.addTask(task1);
    RR_Scheduler.addTask(task2);
    RR_Scheduler.addTask(task3);
    RR_Scheduler.addTask(task4);
    RR_Scheduler.addTask(task5);
    RR_Scheduler.addTask(task6);

    // Execute tasks
    std::cout << "RR Algorithm:\n";
    RR_Scheduler.scheduleTasks(cpu);

    // Add tasks to the SJF Scheduler
    ShortestJob.addTask(task1);
    ShortestJob.addTask(task2);
    ShortestJob.addTask(task3);
    ShortestJob.addTask(task4);
    ShortestJob.addTask(task5);
    ShortestJob.addTask(task6);

    // Execute tasks
    std::cout << "\nShortestJob Algorithm:\n";
    ShortestJob.scheduleTasks(cpu);

    return 0;
}