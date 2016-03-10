#include <iostream>

template<typename ...Args>
void g(Args ...args)
{
	std::cout<<sizeof...(Args)<<std::endl;
	std::cout<<sizeof...(args)<<std::endl;
}
int main()
{
	g(1);
	g(1,2,3);
	g(1,2,3,4,5);
	return 0;
}
