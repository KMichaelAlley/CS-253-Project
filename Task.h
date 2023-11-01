#ifndef TASK_H
#define TASK_H

#include <chrono>
#include <iostream>
using namespace std;

class Task {
public:
    // Constructor
    Task(int year, int month, int day, int hour, int minute, int priority, string category, string description);

    //setters
    void setDueDate(int y, int m, int d, int h, int minute);
    void setPriority(int p) { this->priority = p; }
    void setCategory(string c) { category = c; }
    void setDescription(string d) { description = d; }

    //getters
    chrono::system_clock::time_point getDueDateTime() const;
    int getPriority() { return priority; }
    string getCategory() { return category; }
    string getDescription() { return description; }

    //other
    void print();


private:
    tm dueDate;
    int priority;
    string category;
    string description;
};

#endif