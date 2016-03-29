#include <stdio.h>

struct school{
	int a;
	int b;
};

int main()
{
	struct school s1={
		.a=1,
		.b=2,
	};
	int *pa=&s1.b;
    printf("%lu\n",__builtin_offsetof(struct school,b));
    return 0;
}
