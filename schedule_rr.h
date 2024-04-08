#pragma once

#include "scheduler.h"

class RR : public Scheduler {
public:
    void scheduleTasks(CPU& cpu) override;
};