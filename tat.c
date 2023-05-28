//
#include<stdio.h>
int main()
{
	int p[100],b[100],wt[100],tat[100];
	int n,i,sum=0,sum1=0;
	float avg,avg1;
	printf("Enter no of processes: ");
	scanf("%d",&n);
	printf("Enter the process name: ");
	for(i=0; i<n; i++)
	{
		scanf("%d",&p[i]);
	}
	printf("Enter the burst time of the process\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&b[i]);
	}
	wt[0]=0;
	for(i=1; i<n; i++)
	{
		wt[i] = wt[i-1]+b[i-1];
	}
	for(i=0; i<n; i++)
	{
		tat[i] = b[i]+wt[i];
	}
	printf("Process\t\tBurst Time\tWaiting Time\tTurst Around Time\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\n",p[i],b[i],wt[i],tat[i]);
	}
	for(i=0; i<n; i++)
	{
		sum = sum+wt[i];
		sum1 = sum1+tat[i];
	}
	avg = (float)sum/n;
	avg1 = (float)sum1/n;
	printf("Avg waiting time=%f\n",avg);
	printf("Avg trn around time = %f\n",avg1);
}

