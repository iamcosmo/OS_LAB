//Bankers algo
#include<stdio.h>
#define n 5
#define m 3
int available[m],max[n][m],allocation[n][m],need[n][m],i,j,k;
void calculateNeed()
{
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			need[i][j] = max[i][j]-allocation[i][j];
		}
	}
}
bool is_safe_state(int request[])
{
	bool found=false,possible=true;
	int count=0;
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
					possible=true;
					//printf("if--for\n");
					if(need[i][j]>work[j])
					{
						possible=false;
						break;
					}
				}
				if(!possible)
				{
					//printf("if-if\n");
					for(k=0;k<m; k++)
						work[k]+=allocation[i][k];
					safeSeq[count++] = i;
					finish[i] = 1;
					found=true;
				}
			}
		}
		if(found==false)
		{
			//printf("while-if\n");
			printf("System is not in safe State!\n");
			return false;
		}
	}
	printf("Safe Sequence: ");
	for(i=0; i<n; i++)
		printf("%d ",safeSeq[i]);
	printf("\n");
	return true;
}
int main()
{
}
