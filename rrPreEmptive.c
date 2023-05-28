//Round Robin PreEmptive
#include<stdio.h>
#include<stdlib.h>
void roundRobin(int at[], int bt[], int n, int quant)
{
	float avg_tat=0.0,avg_wt=0.0;
	int i,j,time=0,count=0,remaining=n;
	//int *done = (int*)malloc(sizeof(int)*n);
	int done[n];
	int ct[n],tat[n],wt[n],rt[n];
	for(i=0; i<n; i++)
	{
		rt[i] = bt[i];
		done[i] = 0;
	}
	while(remaining>0)
	{
		for(i=0; i<n; i++)
		{
			if(done[i])
			{
				continue;
			}
		
			if(rt[i]>quant)
			{
				time += quant;
				rt[i] -= quant;
			}
			else
			{
				time+=rt[i];
				rt[i]=0;
				done[i] = 1;
				remaining--;
				ct[i] = time;
				tat[i] = ct[i]-at[i];
				wt[i] = tat[i]-bt[i];
			}
		}
	}
	printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\t\tTAT\tWaiting TIme\n");
	for(i=0; i<n; i++)
	{
		avg_tat += tat[i];
		avg_wt += wt[i];
		printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	avg_tat/=n;
	avg_wt/=n;
	printf("Average Turn Around Time = %f\n",avg_tat);
	printf("Average Waiting time = %f\n",avg_wt);
}
int main()
{

	int n,quantum,i;
	printf("Enter the no of Processes: ");
	scanf("%d",&n);
	int bt[n],at[n];
	for(i=0; i<n; i++)
	{
		printf("Process ID: %d\n",i+1);
		printf("Enter Arrival Time: ");
		scanf("%d",&at[i]);
		printf("Enter Burst Time: ");
		scanf("%d",&bt[i]);
	}
	printf("Enter the Time Quantum: ");
	scanf("%d",&quantum);
	roundRobin(at,bt,n,quantum);
	return 0;
}
