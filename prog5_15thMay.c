//
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int n;
	char a[20];
	printf("Enter the Message: \n");
	scanf("%s",a);
	int p[2],i,pid;
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		printf("Parent block\n");
		write(p[1],a,strlen(a));
		sleep(10);
	}
	else if(pid==0)
	{
		printf("Child Block\n");
		read(p[0],a,strlen(a));
		printf("%s\n",a);
	}
	else
		printf("Error\n");
	return 0;
}

