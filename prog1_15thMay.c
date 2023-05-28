//
#include<stdio.h>
#include<unistd.h>
int main()
{
	int p[2];
	pipe(p);
	printf("p[0] is %d p[1] is %d\n",p[0],p[1]);
}
