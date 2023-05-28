//Bankers algo
#include<stdio.h>
#define n 5
#define m 3
int main()
{
	int available[m], max[n][m], allocation[n][m],need[n][m],i,j,k,found=0,count=0;
	printf("Enter the available resources: \n");
	for(i=0; i<m; i++)
	{
		scanf("%d",&available[i]);
	}
	printf("Enter the max demand and allocated resources to each process: \n"); 
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			scanf("%d %d",&max[i][j],&allocation[i][j]);
			need[i][j] = max[i][j]-allocation[i][j];
		}
	}
	int finish[n] = {0};
	int safeSeq[n];
	int work[m];
	for(i=0; i<m; i++)
		work[i] = available[i];
	
	while(count<n)
	{
		//printf("while\n");
		for(i=0; i<n; i++)
		{
			//printf("For\n");
			if(finish[i]==0)
			{
				//printf("if\n");
				for(j=0; j<m; j++)
				{
					//printf("if--for\n");
					if(need[i][j]>work[j])
						break;
				}
				if(j==m)
				{
					//printf("if-if\n");
					for(k=0;k<m; k++)
						work[k]+=allocation[i][k];
					safeSeq[count++] = i;
					finish[i] = 1;
					found=1;
				}
			}
		}
		if(found==0)
		{
			//printf("while-if\n");
			printf("System is not in safe State!\n");
			return -1;
		}
	}
	printf("Available Resources: \n");
	for(i=0; i<m; i++)
		printf("%d\t",available[i]);
	printf("\n");
	printf("\nMaximum resources: \n");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d\t",max[i][j]);
		}
		printf("\n");
	}
	printf("\nAllocated Resources: \n");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; i++)
		{
			printf("%d\t",allocation[i][j]);
		}
		printf("\n");
	}
	printf("\nSafe Sequence: ");
	for(i=0; i<n; i++)
		printf("%d ",safeSeq[i]);
	printf("\n");
	return 0;
}
