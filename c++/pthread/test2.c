#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	long int i=100000;
	while(i)
	{
		if(i%2==0)
			cout<<"inc"<<i<<endl;
		else
			cout<<"show:"<<i<<endl;
		i--;
	}
	return 0;
}
