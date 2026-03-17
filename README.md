# CPU Scheduling - Non Preemptive Priority

## Description
This program implements Non-Preemptive Priority Scheduling in C.
Higher priority value indicates higher priority.

## Input Format
PID AT BT PR

Example:
P1 0 5 2  
P2 0 4 5  
P3 1 3 1  

## Output
- Waiting Time
- Turnaround Time
- Average Waiting Time
- Average Turnaround Time

## Algorithm
1. Select process with highest priority among arrived processes
2. Execute it completely (non-preemptive)
3. Update waiting time and turnaround time
4. Repeat until all processes are completed
