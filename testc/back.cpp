#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int a[5]={1,2,3,4,5};
	std::vector<int> v;
	copy(std::begin(a),std::end(a),back_inserter(v));
	for(const auto &item : v)
	{
		std::cout<<item<<std::endl;
	}
	return 0;
}
