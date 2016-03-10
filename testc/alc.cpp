#include <iostream>
#include <memory>
#include <string>

using std::string;
using std::allocator;

int main()
{
	allocator<int> alc;
	auto const p=alc.allocate(5);
	for(const auto &item:{0,1,2,3,4})
	{
		std::cout<<p+item<<',';
		alc.construct(p+item,item);
	}
	auto const q=alc.allocate(5);
	for(const auto &item:{0,1,2,3,4})
	{
		std::cout<<q+item<<',';
		alc.construct(q+item,item+5);
	}
	for(const auto &item:{0,1,2,3,4})
	{
	    std::cout<<q[item]<<' ';	
	}
	std::cout<<p<<':'<<q<<std::endl;
	std::cout<<std::endl;
	return 0;
}
