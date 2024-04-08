#include <iostream>
#include "task.h"
#include "schedule_sjf.h"
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
    SJF sjf_scheduler;

    // Add tasks to the scheduler
    sjf_scheduler.addTask(task1);
    sjf_scheduler.addTask(task2);
    sjf_scheduler.addTask(task3);
    sjf_scheduler.addTask(task4);
    sjf_scheduler.addTask(task5);
    sjf_scheduler.addTask(task6);

    // Schedule and execute tasks
    sjf_scheduler.scheduleTasks(cpu);

    return 0;
}