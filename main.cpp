#include <iostream>
#include "task.h"
#include "schedule_sjf.h"
#include "schedule_rr.h"
#include "cpu.h"

int main() {
    // Create tasks
    Task task1("Task1", 1, 10);
    Task task2("Task2", 2, 5);
    Task task3("Task3", 3, 8);
    Task task4("Task4", 3, 5);
    Task task5("Task5", 3, 81);
    Task task6("Task6", 3, 8);

    // Create a CPU
    CPU cpu;

    // Create a FCFS scheduler
    RR rr_scheduler(10);

    // Add tasks to the scheduler
    rr_scheduler.addTask(task1);
    rr_scheduler.addTask(task2);
    rr_scheduler.addTask(task3);
    rr_scheduler.addTask(task4);
    rr_scheduler.addTask(task5);
    rr_scheduler.addTask(task6);

    // Schedule and execute tasks
    rr_scheduler.scheduleTasks(cpu);

    return 0;
}