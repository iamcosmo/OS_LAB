//
#include<stdio.h>
int wt[100], tat[100];
int sum=0,sum1=0;
float avg,avg1;//,avg2,avg3;
int fcfs(int[],int[],int);
int sgf(int[],int[],int);
int priority(int[],int[],int[],int);
int main()
{
	int a[100],b[100],p[100];//,tat[100],wt[100];
	int n,i,fcfs1,sgf1,priority1;
	//int sum=0,sum1=0;
	//float avg,avg1,avg2,avg3;
	int max,pos,temp,temp1,t;
	printf("Enter no of processes: ");
	scanf("%d",&n);
	printf("Enter the process name: ");
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the burst time of the process\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&b[i]);
	}
	printf("Enter the priority: ");
	for(i=0; i<n; i++)
	{
		scanf("%d",&p[i]);
	}
	fcfs1=fcfs(a,b,n);
	sgf1=sgf(a,b,n);
	priority1=priority(a,b,p,n);
	
}
int fcfs(int a[], int b[], int n)
{
	int wt[100],tat[100];
	int i;

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
		printf("%d\t\t%d\t\t%d\t\t%d\n",a[i],b[i],wt[i],tat[i]);
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


//
int sjf(int a[], int b[], int n)
{
	int wt[100],tat[100];
	int i,min,temp,temp1,pos,j;
	for(i=0;i<n; i++)
	{
		min = b[i];
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(b[j]<min)
			{
				min=b[j];
				pos=j;
			}
		}
		if(pos!=i)
		{
			temp = b[i];
			b[i] = b[pos];
			b[pos] = temp;
			temp1= a[i];
			a[i] = a[pos];
			a[pos] = temp1;
		}
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
		printf("%d\t\t%d\t\t%d\t\t%d\n",a[i],b[i],wt[i],tat[i]);
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
//
int priority(int a[],int b[],int p[], int n)
{
	int wt[100],tat[100];
	int i,min,temp,temp1,temp3,pos,j;
	
	for(i=0;i<n; i++)
	{
		min = p[i];
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(p[j]<min)
			{
				min=p[j];
				pos=j;
			}
		}
		if(pos!=i)
		{
			temp3=p[i];
			p[i] = p[pos];
			p[pos] = temp3;
			temp = b[i];
			b[i] = b[pos];
			b[pos] = temp;
			temp1= a[i];
			a[i] = a[pos];
			a[pos] = temp1;
		}
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
	printf("Process\t\tBurst Time\tPriority\tWaiting Time\tTurst Around Time\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",a[i],b[i],p[i],wt[i],tat[i]);
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

