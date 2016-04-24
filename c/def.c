#include <stdio.h>

#define SHOW(fmt,args...) printf(fmt,##args)

int main()
{
	SHOW("%d\n",10);
	SHOW("%s ","hello");
	SHOW("word!\n");
	return 0;
}

