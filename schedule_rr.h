#pragma once

#include "scheduler.h"

class RR : public Scheduler {
private:
    int timeQuantum;

public:
    RR(int timeQuantum);
    void scheduleTasks(CPU& cpu) override;
};