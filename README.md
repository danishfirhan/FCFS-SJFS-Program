# CPU Scheduling Algorithm

This project implements two CPU scheduling algorithms: First Come First Serve (FCFS) and Shortest Job First (SJF). The program takes input parameters such as the number of processes, arrival time, and burst time for each process. It then computes the waiting time, turnaround time, average waiting time, and average turnaround time for each process.

## Features

- **First Come First Serve (FCFS)**: Processes are executed in the order they arrive.
- **Shortest Job First (SJF)**: Processes with the shortest burst time are executed first, allowing for efficient resource utilization.

## Program Input

The program prompts the user to choose an algorithm and input the following parameters:
- Number of processes
- Arrival time and burst time for each process

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your_username/cpu-scheduling-algorithm.git
   ```

2. Compile the program:

   ```bash
   g++ main.cpp ProcessScheduler.cpp Process.cpp -o scheduler
   ```

3. Run the program:

   ```bash
   ./scheduler
   ```

## Usage

1. Choose an algorithm: FCFS or SJF.
2. Enter the number of processes.
3. Enter the arrival time and burst time for each process.
4. View the scheduling results, including waiting time, turnaround time, and Gantt chart.

## Example

```bash
Choose an algorithm:
[1] - First Come First Serve (FCFS)
[2] - Shortest Job First (SJF)
> 2

Enter number of processes:
> 4

Enter the arrival time and burst time for Process 1:
Arrival Time: > 0
Burst Time: > 7

Enter the arrival time and burst time for Process 2:
Arrival Time: > 2
Burst Time: > 4

Enter the arrival time and burst time for Process 3:
Arrival Time: > 4
Burst Time: > 1

Enter the arrival time and burst time for Process 4:
Arrival Time: > 5
Burst Time: > 4

PROCESS         ARRIVAL TIME    BURST TIME      WAITING TIME    TURNAROUND TIME
P1              0               7               0               7
P3              1               4               3               4
P2              2               4               6               10
P4              4               5               7               12

Average Waiting Time: 4
Average Turnaround Time: 8

GANTT CHART
|P1|****P3****|****P2****|******P4******|
0   7        11       15               20
```


---
