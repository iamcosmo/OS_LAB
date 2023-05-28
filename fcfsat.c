//
#include<stdio.h>
void sortAT(int p[], int at[], int bt[], int n)
{
	int i,j,temp;
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(at[i]>at[j])
			{
				temp = at[i];
				at[i] = at[j];
				at[j] = temp;

				temp = bt[i];
				bt[i] = bt[j];
				bt[j] = temp;

				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}
int main()
{
	int p[100],b[100],st[100],wt[100],tat[100],at[100];
	int n,i,sum=0,sum1=0;
	float avg,avg1;
	printf("Enter no of processes: ");
	scanf("%d",&n);
	printf("Enter the process name: ");
	for(i=0; i<n; i++)
	{
		scanf("%d",&p[i]);
	}
	printf("Enter the arrival time & burst time of the process\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&at[i]);
		scanf("%d",&b[i]);
	}
	sortAT(p,at,b,n);
	st[0]=0;
	for(i=1; i<n; i++)
	{
		st[i] = st[i-1]+b[i-1];
	}
	for(i=0; i<n; i++)
	{
		wt[i] = st[i]-at[i];
	}	
	for(i=0; i<n; i++)
	{
		tat[i] = b[i]+wt[i];
	}
	printf("Process\t\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],at[i],b[i],wt[i],tat[i]);
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

