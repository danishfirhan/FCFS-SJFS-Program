#ifndef PROCESS_H
#define PROCESS_H
#include <iostream>
using namespace std;

class Process {
private:
    string processName;
    int arrivalTime;
    int burstTime;
public:
    int waitingTime;
    int turnaroundTime;
    Process(string processName, int arrivalTime, int burstTime) {
        this->processName = processName;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
    }
    Process(string processName, int burstTime) {
        this->processName = processName;
        this->burstTime = burstTime;
    }
    void setProcessName(string processName) {
        this->processName = processName;
    }
    void setArrivalTime(int arrivalTime) {
        this->arrivalTime = arrivalTime;
    }
    void setBurstTime(int burstTime) {
        this->burstTime = burstTime;
    }
    string getProcessName() {
        return this->processName;
    }
    int getArrivalTime() {
        return this->arrivalTime;
    }
    int getBurstTime() {
        return this->burstTime;
    }
};
#endif
