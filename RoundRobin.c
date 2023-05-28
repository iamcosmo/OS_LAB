//
#include<stdio.h>
void roundRobin(int [], int [], int [], int, int);
int main()
{
	int i,NOP,n,quant,wt=0,tat=0,at[100],bt[100],temp[100];
	printf("Enter the no of process: ");
	scanf("%d",&NOP);
	n=NOP;
	printf("Enter the Arrival time and burst time for the processes: \n");
	for(i=0; i<NOP; i++)
	{
		at[i]=0;
		printf("Burst Time - %d: ",i);
		scanf("%d",&bt[i]);	
		temp[i] = bt[i];
	}
	printf("Enter the time quantum for the RR process: ");
	scanf("%d",&quant);
	roundRobin(at,bt,temp,n,quant);
}
void roundRobin(int a[], int b[], int tmp[], int n, int q)
{
	int NOP = n;
	int i,sum,count=0,tat[100],wt[100];
	int wtt=0,tatt=0;
	float avg_wt,avg_tat;
	printf("Process\t\tBurst time\tTAT\tWaiting time\n");
	for(sum=0,i=0;n!=0;)
	{
		if(tmp[i]<=q&&tmp[i]>0)
		{
			sum = sum+tmp[i];
			tmp[i] = 0;
			count=1;
		}
		else if(tmp[i]>0)
		{
			tmp[i] = tmp[i]-q;
			sum = sum + q;
		}
		
		if(tmp[i]==0&&count==1)
		{
			n--;
			printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,b[i],sum-a[i],sum-a[i]-b[i]);
			wtt = wtt+ sum-a[i]-b[i];
			tatt = tatt+sum-a[i];
			count=0;
		}
		if(i==NOP-1)
			 i = 0;
		else if(a[i+1]<=sum)
			i++;
		else
			i=0;
	}
	avg_wt = wtt * 1.0/NOP;
	avg_tat = tatt * 1.0/NOP;

	printf("The avrage Waiting time: %f\n",avg_wt);
        printf("The average turn around time: %f\n",avg_tat);	
}
			


