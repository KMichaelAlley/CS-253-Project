#ifndef DAY_H
#define DAY_H

#include <chrono>
#include <iostream>
#include "Task.h"
#include <vector>
using namespace std;

class Day : public Task {
public:
    Day(int year, int month, int day) : Task(year, month, day, 0, 0, 0, "", "Day Schedule") {}

    //Setters
    void setMorningTime(int startTime, int endTime);
    void setNoonTime(int startTime, int endTime);
    void setAfternoonTime(int startTime, int endTime);
    void setEveningTime(int startTime, int endTime);

    // Getters
    std::chrono::
    system_clock::time_point getMorningStartTime(){return MorningStartTime;}
    std::chrono::
    system_clock::time_point getMorningEndTime(){return MorningEndTime;}

    std::chrono::
    system_clock::time_point getNoonStartTime(){return NoonStartTime;}
    std::chrono::
    system_clock::time_point getNoonEndTime(){return NoonEndTime;}

    std::chrono::
    system_clock::time_point getAfternoonStartTime(){return AfternoonStartTime;}
    std::chrono::
    system_clock::time_point getAfternoonEndTime(){return AfternoonEndTime;}

    std::chrono::
    system_clock::time_point getEveningStartTime(){return eveningStartTime;}
    std::chrono::
    system_clock::time_point getEveningEndTime(){return eveningEndTime;}





private:
    // Schedule inherited from Task class
    vector<Task> schedule;

    // TimeBlocks
    std::chrono::system_clock::time_point MorningStartTime;
    std::chrono::system_clock::time_point MorningEndTime;

    std::chrono::system_clock::time_point NoonStartTime;
    std::chrono::system_clock::time_point NoonEndTime;

    std::chrono::system_clock::time_point AfternoonStartTime;
    std::chrono::system_clock::time_point AfternoonEndTime;

    std::chrono::system_clock::time_point eveningStartTime;
    std::chrono::system_clock::time_point eveningEndTime;

};
#endif