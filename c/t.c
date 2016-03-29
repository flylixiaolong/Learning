#include <stdio.h>

struct filed{
	unsigned int a:2;
	unsigned int b:2;
	unsigned int c:4;
};

int main(){
	struct filed test={
		1,2,3};
	char *pf=(char*)&test;
	printf("%d,%d,%d\n",test.a,test.b,test.c);
	printf("%p\n",*pf);
	return 0;
}
