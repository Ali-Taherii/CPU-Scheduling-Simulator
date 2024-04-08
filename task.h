#pragma once

#include <string>

class Task {
private:
    std::string name;
    int priority;
    int burst;
    int remaining_burst;

public:
    // Constructor
    Task(const std::string& name, int priority, int burst);

    // Accessors
    std::string getName() const;
    int getPriority() const;
    int getBurst() const;
    int getRemainingBurst() const;

    // Modifiers
    void setRemainingBurst(int remaining);
};