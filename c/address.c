#include <stdio.h>

int main()
{
	int a[10]={};
	printf("%lu\n",(unsigned long)((char*)&a[9]-(char*)&a[0]));
	return 0;
}
