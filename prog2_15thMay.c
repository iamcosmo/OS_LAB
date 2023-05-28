//
#include<stdio.h>
#include<unistd.h>
int main()
{
	int p[2],retval,i=0;
	while(1)
	{
		retval=pipe(p);
		if(retval==-1)
		{
			printf("MAximum no of pipes that can be  opened concurrently are %d\n",i);
			break;
		}
		i++;
		printf("p[0] is %d p[1] is %d\n",p[0],p[1]);
	}
	return 0;
}
