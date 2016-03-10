#include <iostream>
#include <vector>
#include <set>

int main()
{
	std::vector<char> v;
	std::set<char> m={'a','b','c'};
	copy(m.begin(),m.end(),back_inserter(v));
	for(const auto &item : v)
	{
		std::cout<<item<<std::endl;
	}
	return 0;
}
