#include <iostream>
#include <string>
#include <functional>

using std::string;
using std::bind;
using std::placeholders::_1;
using std::placeholders::_2;

template<typename T,size_t N>
void print(const T(&list)[N],char sep,char newline)
{
	for(const auto &item:list)
	{
		std::cout<<item<<sep;
	}
	std::cout<<newline;
}
int main()
{
    string str[4]={"where","are","you","?"};
	print(str,' ','\n');
	auto newprint=bind(print<string,4>,_1,' ','\n');
	newprint(str);
	return 0;
}
