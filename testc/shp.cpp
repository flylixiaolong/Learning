#include <iostream>
#include <vector>
#include <memory>

using std::shared_ptr;
using std::vector;
using std::cout;
using std::endl;

int main()
{
	shared_ptr<vector<int>> pv(new vector<int>);
	*pv={1,2,3,4};
	for(auto item:*pv)
	{
		cout<<item<<endl;
	}
	vector<int> ve;
	ve={1,2,3,4};
	for(auto item:ve)
	{
		cout<<item<<endl;
	}
	cout<<len(ve)<<endl;
	return 0;
}
