//SRTF

#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};


void get_process_details(struct process *processes, int n) 
{
    int i;
    for (i = 0; i < n; i++) 
    {
        processes[i].pid = i + 1;
        printf("Process %d:\n", processes[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }
}


void sort_by_arrival_time(struct process *processes, int n) 
{
    int i, j;
    for (i = 0; i < n; i++) 
    {
	for (j = i + 1; j < n; j++) 
    	{
		if (processes[i].arrival_time > processes[j].arrival_time) 
	    	{
            		struct process temp = processes[i];
            		processes[i] = processes[j];
            		processes[j] = temp;
            	}	
    	}
    }
    
}


void run_srtf(struct process *processes, int n) 
{
    int i, time = 0, total_burst_time = 0, min, index;
    float avg_turnaround_time = 0, avg_waiting_time = 0;

    
    for (i = 0; i < n; i++) 
        total_burst_time += processes[i].burst_time;

    printf("Process ID      Arrival Time    Burst Time      Completion Time Turnaround Time Waiting Time\n");
    for (time = processes[0].arrival_time; time < total_burst_time;) 
    {
        min = 99999;
        index = n;
        for (i = 0; i < n; i++) 
	{
            if (processes[i].arrival_time <= time && processes[i].remaining_time < min && processes[i].remaining_time > 0) 
	    {
                min = processes[i].remaining_time;
                index = i;
            }
        }
        if (index == n) 
	{
            time++;
            continue;
	}
        processes[index].remaining_time--;
        if (processes[index].remaining_time == 0)
       	{
            processes[index].completion_time = time + 1;
            processes[index].turnaround_time = processes[index].completion_time - processes[index].arrival_time;
            processes[index].waiting_time = processes[index].turnaround_time - processes[index].burst_time;
            avg_turnaround_time += processes[index].turnaround_time;
            avg_waiting_time += processes[index].waiting_time;
        }
        time++;
    }
    
    for (i = 0; i < n; i++) 
    {
        printf("%-15d%-15d%-15d%-15d%-15d%-15d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

	avg_turnaround_time /= n;
	avg_waiting_time /= n;
	printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
	printf("Average Waiting Time: %.2f\n", avg_waiting_time);
}
int main() 
{
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", &n);

	struct process *processes = (struct process*) malloc(n * sizeof(struct process));
	get_process_details(processes, n);
	sort_by_arrival_time(processes, n);
	run_srtf(processes, n);
	free(processes);

	return 0;
}

