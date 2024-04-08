#include <iostream>
#include "task.h"
#include "scheduler.h"
#include "cpu.h"

int main() {
    // Create tasks
    Task task1("Task1", 1, 10);
    Task task2("Task2", 2, 5);
    Task task3("Task3", 3, 8);

    // Create a CPU
    CPU cpu;

    // Create a scheduler
    Scheduler scheduler;

    // Add tasks to the scheduler
    scheduler.addTask(task1);
    scheduler.addTask(task2);
    scheduler.addTask(task3);

    // Schedule and execute tasks
    scheduler.scheduleTasks(cpu);

    return 0;
}
