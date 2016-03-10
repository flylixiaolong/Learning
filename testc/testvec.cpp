#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	vector<int> v{1,2,3,4,5};
	vector<int> *pv=&v;
	cout<<(*pv)[0]<<endl;
	int a[5]={1,2,3,4,5};
	int (*p)[5]=&a;
	cout<<(*p)[0]<<endl;
	return 0;
}
