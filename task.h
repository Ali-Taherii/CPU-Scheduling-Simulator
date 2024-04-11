#pragma once

#include <string>

class Task {
protected:
    std::string name;
    int burst;
    int remaining_burst;

public:
    // Constructor
    Task(const std::string& name, int burst);

    // Accessors
    std::string getName() const;
    int getBurst() const;
    int getRemainingBurst() const;

    // Modifier
    void setRemainingBurst(int remaining);

    // Pure virtual function
    virtual void execute() = 0;
};