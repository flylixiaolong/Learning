#include <iostream>
#include <vector>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;

int main()
{
    shared_ptr<vector<int>> pa(new vector<int>);
    *pa={1,2,3,4,5};
    for(auto item:*pa)
    {
	cout<<item<<endl;
    }
    cout<<pa->size()<<endl;
    int ar[5]={1,2,3,4,5};
    cout<<(ar.begin())<<endl; 
    return 0;
}
