#include <sys/param.h>

int main()
{
	for(int i=0;i<NOFILE;i++)
		close(i);
	return 0;
}
