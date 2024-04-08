#ifndef PROCESSSCHEDULER_H
#define PROCESSSCHEDULER_H
#include <string>
#include <vector>
#include "Process.h"

class ProcessScheduler {
private:
    vector<Process> processList;
    string algorithm;

    void sortFCFS() {
        for (int i = 0; i < this->processList.size(); i++) {
            for (int j = 0; j < this->processList.size() - 1; j++) {
                if (this->processList[j].getArrivalTime() > this->processList[j + 1].getArrivalTime()) {
                    swap(&processList[j], &processList[j + 1]);
                }
            }
        }
    }

    void sortShortestJob() {
        for (int i = 0; i < this->processList.size(); i++) {
            for (int j = 0; j < this->processList.size() - 1; j++) {
                if (this->processList[j].getArrivalTime() > this->processList[j + 1].getArrivalTime()) {
                    swap(&processList[j], &processList[j + 1]);
                }
                else if (this->processList[j].getArrivalTime() == this->processList[j + 1].getArrivalTime()) {
                    // If arrival times are equal, compare burst times
                    if (this->processList[j].getBurstTime() > this->processList[j + 1].getBurstTime()) {
                        swap(&processList[j], &processList[j + 1]);
                    }
                }
            }
        }
    }


    static void swap(Process* p1, Process* p2) {
        Process temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }

public:
    ProcessScheduler(vector<Process> processList, string algorithm) {
        this->processList = processList;
        this->algorithm = algorithm;
    }

    vector<Process> scheduleProcesses() {
        if (algorithm == "SJF") {
            sortShortestJob();
        }

        int currentTime = 0;
        int totalWaitingTime = 0;
        for (int i = 0; i < this->processList.size(); i++) {
            if (currentTime < processList[i].getArrivalTime()) {
                currentTime = processList[i].getArrivalTime();
            }
            processList[i].waitingTime = currentTime - processList[i].getArrivalTime();
            totalWaitingTime += processList[i].waitingTime;
            currentTime += processList[i].getBurstTime();
            processList[i].turnaroundTime = processList[i].waitingTime + processList[i].getBurstTime();
        }
        return this->processList;
    }

    string buildGanttChart() {
        string chart = "";
        int time = 0;

        for (Process p : processList) {
            int currentCount = p.getBurstTime() * 2;

            chart += "|";

            currentCount -= p.getProcessName().size();
            for (int i = 0; i < currentCount / 2; i++) {
                chart += "*";
            }

            chart += p.getProcessName();

            currentCount -= currentCount / 2;

            for (int i = 0; i < currentCount; i++) {
                chart += "*";
            }
        }

        chart += "|\n" + to_string(time);

        for (Process p : processList) {
            int s;
            if (p.getBurstTime() < p.getProcessName().length()) {
                s = p.getProcessName().length();
            }
            else {
                s = p.getBurstTime() * 2;
            }
            s -= (to_string(time).length() - 1);
            for (int i = 0; i < s; i++) {
                chart += " ";
            }
            time += p.getBurstTime();
            chart += to_string(time);
        }
        return chart;
    }
};

#endif
