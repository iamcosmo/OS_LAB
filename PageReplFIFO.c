//Page Replacement methods :- FIFO
#include<stdio.h>
#include<stdlib.h>
#define FRAME 3

int main()
{
	int box[FRAME];
	int n,i,j=0,k;
	printf("Enter the size of the string : ");
	scanf("%d",&n);
	int str[n];
	//int str[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	
	printf("Enter the array of string: ");
	for(i=0; i<FRAME; i++)
		scanf("%d",&str[i]);
	
	for(i=0; i<n; i++)
		printf("%d\t",str[i]);
	printf("\n");
	int fault_counts = 0;

	for(i=0; i<FRAME; i++)
	{
		box[i] = -1;
	}
	for(i=0; i<n; i++)
	{
		if(j==FRAME)
			j=0;
		printf("j=%d\n",j);
		
		printf("The current box matrix is: ");
		for(k=0; k<FRAME; k++)
			printf("%d\t",box[k]);
		printf("\nFault Counts: %d\n",fault_counts);
		
		if(box[j]==-1)
		{
			++fault_counts;
			box[j++] = str[i];
			continue;
		}
		else
		{
			printf("str[%d]=%d\tbox[%d]=%d\n",i,str[i],j,box[j]);

			int l=j-1;
			int r=j+1;
			if(str[i]!=box[j])
				while(l>=0||r<FRAME)
				{
					printf("l=%d\tr=%d\n",l,r);					
					if(l>=0)
					{
						if(str[i]==box[l])
						{
							r=-11;
							l=-11;
							break;
						}						
					}
					if(r<FRAME)
					{
						if(str[i]==box[r])
						{
							r=-11;
							l=-11;
							break;
						}
					}
					r++;
					l--;					
			
				}
			else
			{
				printf("Page Hit found\n");
				//j++;
				continue;
			}
			
			if(r==-11&&l==-11)
			{
				printf("Page Hit Found\n");
				//++j;
				continue;
			}
			else
			{
				printf("Fault Count\n");
				++fault_counts;
				box[j++] = str[i];
			}

		}
		
	}
	printf("The Last Box Matrix is: \n");
	for(k=0; k<FRAME; k++)
		printf("%d\t",box[k]);
	printf("\nTotal Fault Counts: %d\n",fault_counts);
	return 0;
}
		
