#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

template < typename T, size_t N>//T是类型参数，N是非类型参数
void print (const T (&a)[N] )
{
	for(const auto &item:a)
	{
		cout<<item<<' ';
	}
	cout<<endl;
}
int main()
{
	int a[10]={};
	int b[5]={1,2,3,4,5};
	print(a);
	print(b);
	string s[4]={"where","are","you","?"};
	print(s);
	return 0;
}
