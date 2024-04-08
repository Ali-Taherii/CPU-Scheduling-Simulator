#pragma once

#include "scheduler.h"

class FCFS : public Scheduler {
public:
    void scheduleTasks(CPU& cpu) override;
};
