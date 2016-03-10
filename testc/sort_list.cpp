#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

int main()
{
	std::list<int> ls{1,6,4,3,5,2};
	ls.sort();
	for(const auto &item:ls)
	{
		std::cout<<item<<std::ends;
	}
	std::cout<<std::endl;
	std::vector<int> vc{1,6,3,5,2,4};
	sort(vc.begin(),vc.end());
	for(const auto &item:vc)
	{
		std::cout<<item<<std::ends;
	}
	std::cout<<std::endl;
	return 0;
}
