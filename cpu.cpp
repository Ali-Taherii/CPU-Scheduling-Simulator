#include "cpu.h"

void CPU::runTask(PriorityTask& task) {
	task.execute();
}

void CPU::runTask(NonPriorityTask& task) {
	task.execute();
}