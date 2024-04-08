#include <iostream>
#include <string>
#include <vector>
#include "Process.h"
#include "ProcessScheduler.h"

using namespace std;

int main() {
    int choiceOfAlgorithm;
    string algorithm;
    int processCount;

    while (algorithm.empty()) {
        cout << "Choose an algorithm: \n"
            << "[1] - First Come First Serve (FCFS)\n"
            << "[2] - Shortest Job First (SJF)\n>";

        cin >> choiceOfAlgorithm;
        if (choiceOfAlgorithm == 1) {
            algorithm = "FCFS";
            cout << "\nFIRST COME FIRST SERVE CPU SCHEDULING";
        }
        else if (choiceOfAlgorithm == 2) {
            algorithm = "SJF";
            cout << "\nSHORTEST JOB FIRST CPU SCHEDULING";
        }
    }

    cout << "\n\nEnter number of processes:\n>";
    cin >> processCount;
    cout << "\n";

    vector<Process> processList;

    for(int i=1; i<=processCount; i++){
    int arrivalTime, burstTime;
    cout << "Enter the arrival time and burst time for Process " << i << "\n";
    if(algorithm == "FCFS" || algorithm == "SJF"){ // Prompt for arrival time for both algorithms
        cout << "Arrival Time: \n>";
        cin >> arrivalTime;
    }
    cout << "Burst Time: \n>";
    cin >> burstTime;

    if(algorithm == "FCFS" || algorithm == "SJF"){ // Create Process object based on algorithm
        processList.push_back(Process("P" + to_string(i), arrivalTime, burstTime)); 
    }
    cout << "\n";
}


    ProcessScheduler processScheduler = ProcessScheduler(processList, algorithm);

    vector<Process> scheduledJobs = processScheduler.scheduleProcesses();

    cout << "PROCESS\t\t" << "ARRIVAL TIME\t" << "BURST TIME\t" << "WAITING TIME\t" << "TURNAROUND TIME\n";
    for (Process proc : scheduledJobs) {
        cout << proc.getProcessName() << "\t\t" << proc.getArrivalTime() << "\t\t" << proc.getBurstTime() << "\t\t" << proc.waitingTime << "\t\t" << proc.turnaroundTime << "\n";
    }


    int averageWaitingTime = 0;
    int averageTurnaroundTime = 0;

    for (Process proc : scheduledJobs) {
        averageWaitingTime += proc.waitingTime;
        averageTurnaroundTime += proc.turnaroundTime;
    }

    averageWaitingTime /= scheduledJobs.size();
    averageTurnaroundTime /= scheduledJobs.size();

    cout << "\nAverage Waiting Time: " << averageWaitingTime << endl;
    cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;

    cout << "GANTT CHART\n";
    cout << processScheduler.buildGanttChart() << endl;
    return 0;
}

