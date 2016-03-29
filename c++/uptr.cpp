#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::unique_ptr;

int main()
{
    int i=0;
    while(1)
    {
	{
	    int *p = new int[100000];
	    delete[] p;
	}
	cout<<i<<',';
    }
    return 0;
}

