#include <iostream>
#include "task.h"
#include "schedule_fcfs.h"
#include "schedule_priority.h"
#include "schedule_priority_rr.h"
#include "cpu.h"

int main() {
    // Create tasks
    Task task1("Task1", 1, 10);
    Task task2("Task2", 2, 5);
    Task task3("Task3", 8, 8);
    Task task4("Task4", 5, 5);
    Task task5("Task5", 5, 20);
    Task task6("Task6", 10, 12);

    // Create a CPU
    CPU cpu;

    // Create a FCFS scheduler
    FCFS FCFS_scheduler;
    // Create a Priority scheduler
    Priority Priority_scheduler;
    // Create a Priority Round Robin scheduler
    PriorityRoundRobin Priority_rr_scheduler(10);


    // Add tasks to the scheduler
    FCFS_scheduler.addTask(task1);
    FCFS_scheduler.addTask(task2);
    FCFS_scheduler.addTask(task3);
    FCFS_scheduler.addTask(task4);
    FCFS_scheduler.addTask(task5);
    FCFS_scheduler.addTask(task6);

    Priority_scheduler.addTask(task1);
    Priority_scheduler.addTask(task2);
    Priority_scheduler.addTask(task3);
    Priority_scheduler.addTask(task4);
    Priority_scheduler.addTask(task5);
    Priority_scheduler.addTask(task6);

    Priority_rr_scheduler.addTask(task1);
    Priority_rr_scheduler.addTask(task2);
    Priority_rr_scheduler.addTask(task3);
    Priority_rr_scheduler.addTask(task4);
    Priority_rr_scheduler.addTask(task5);
    Priority_rr_scheduler.addTask(task6);

    // Schedule and execute tasks
    std::cout << "FCFS Algorithm:\n";
    FCFS_scheduler.scheduleTasks(cpu);

    std::cout << "\nPriority Algorithm:\n";
    Priority_scheduler.scheduleTasks(cpu);

    std::cout << "\nPriority Round Robin Algorithm:\n";
    Priority_rr_scheduler.scheduleTasks(cpu);

    return 0;
}