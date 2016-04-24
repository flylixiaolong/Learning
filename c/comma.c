#include <stdio.h>

int main()
{
	int i=10,j=5;
	do{
		printf("%d,%d\n",i,j);
	}while(j--,i--);
	return 0;
}
