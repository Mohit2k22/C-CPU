//SJF
#include <stdio.h>

int main() {
    int numberOfProcess;

    printf("Enter number of processes: ");
    scanf("%d", &numberOfProcess);

    int process[numberOfProcess], burstTime[numberOfProcess], waitingTime[numberOfProcess], turnAroundTime[numberOfProcess];

    printf("Enter Burst Time:\n");
    for(int i = 0; i < numberOfProcess; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &burstTime[i]);
        process[i] = i + 1;
    }

    // Sorting the burst times in ascending order
    int pos;
    for(int i = 0; i < numberOfProcess; i++) {
        pos = i;
        for(int j = i + 1; j < numberOfProcess; j++) {
            if(burstTime[j] < burstTime[pos])
                pos = j;
        }

        // Swap burst times
        int temp = burstTime[i];
        burstTime[i] = burstTime[pos];
        burstTime[pos] = temp;

        // Swap corresponding processes
        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }

    // Waiting time for the first process is 0
    waitingTime[0] = 0;

    int total = 0;

    // Calculate waiting time for each process
    for(int i = 1; i < numberOfProcess; i++) {
        waitingTime[i] = 0;
        for(int j = 0; j < i; j++) {
            waitingTime[i] += burstTime[j];
        }
        total += waitingTime[i];
    }

    // Calculate average waiting time
    double averageWaitingTime = (double)total / numberOfProcess;

    // Output the results
    printf("Process    Waiting Time    Turnaround Time\n");
    for(int i = 0; i < numberOfProcess; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
        printf("P[%d]\t\t%d\t\t%d\n", process[i], waitingTime[i], turnAroundTime[i]);
    }

    // Print average waiting time with 4 decimal places
    printf("Average waiting time: %.4f\n", averageWaitingTime);

    return 0;
}

