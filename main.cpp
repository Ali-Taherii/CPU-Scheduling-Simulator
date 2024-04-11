#include "priority_task.h"
#include "nonpriority_task.h"
#include "schedule_fcfs.h"
#include "schedule_priority.h"
#include "schedule_priority_rr.h"
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
    
    PriorityTask task7("Task1", 1, 10);
    PriorityTask task8("Task2", 5, 5);
    PriorityTask task9("Task3", 3, 8);
    PriorityTask task10("Task4", 1, 5);
    PriorityTask task11("Task5", 7, 20);
    PriorityTask task12("Task6", 6, 12);

    // Create a CPU
    CPU cpu;

    // Create a FCFS scheduler
    FCFS FCFS_scheduler;
    // Create a Priority scheduler
    Priority Priority_scheduler;
    // Create a Priority Round Robin scheduler
    PriorityRoundRobin Priority_rr_scheduler(10);


    // Add tasks to the FCFS Scheduler
    FCFS_scheduler.addTask(task1);
    FCFS_scheduler.addTask(task2);
    FCFS_scheduler.addTask(task3);
    FCFS_scheduler.addTask(task4);
    FCFS_scheduler.addTask(task5);
    FCFS_scheduler.addTask(task6);

    // Execute tasks
    std::cout << "FCFS Algorithm:\n";
    FCFS_scheduler.scheduleTasks(cpu);

    // Add tasks to the Priority Scheduler
    Priority_scheduler.addTask(task7);
    Priority_scheduler.addTask(task8);
    Priority_scheduler.addTask(task9);
    Priority_scheduler.addTask(task10);
    Priority_scheduler.addTask(task11);
    Priority_scheduler.addTask(task12);

    // Execute tasks
    std::cout << "\nPriority Algorithm:\n";
    Priority_scheduler.scheduleTasks(cpu);

    // Add tasks to the Priority Round Robin Scheduler
    Priority_rr_scheduler.addTask(task7);
    Priority_rr_scheduler.addTask(task8);
    Priority_rr_scheduler.addTask(task9);
    Priority_rr_scheduler.addTask(task10);
    Priority_rr_scheduler.addTask(task11);
    Priority_rr_scheduler.addTask(task12);

    // Execute tasks
    std::cout << "\nPriority Round Robin Algorithm:\n";
    Priority_rr_scheduler.scheduleTasks(cpu);

    return 0;
}