#include <iostream>
#include <utility>
#include <vector>
#include <string>

int main()
{
	std::vector<std::pair<std::string,int>> vp;
	std::pair<std::string,int> p;
	while(std::cin>>p.first&&std::cin>>p.second)
	{
		vp.push_back(p);
	}
	for(const auto &item:vp)
	{
		std::cout<<item.first<<','<<item.second<<std::endl;
	}
	return 0;
}
