#include <stdio.h>
#include "static.h"
//#include "func.h"
//
//void show()
//{
//	printf("func.c\n");
//}

static int s;
extern int s;
extern int s;

int main()
{
	printf("%d\n",s);
	return 0;
}
