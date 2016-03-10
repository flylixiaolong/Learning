#include <iostream>
#include <map>
#include <list>
#include <vector>

int main()
{
	std::map<std::vector<int>::iterator,int> ivi;
	std::map<std::list<int>::iterator,int> lvi;
	std::vector<int> v{5,1,4,2,3};
	std::list<int>   l{1,2,3,4,5};
	auto begin=v.begin(),end=v.end();
	while(begin!=end)
	{
		ivi[begin]=*begin;
		begin++;
	}
	for(const auto &item:ivi)
	{
		std::cout<<*(item.first)<<' '<<item.second<<std::endl;
	}
	return 0;
}
