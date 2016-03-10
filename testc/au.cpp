#include<iostream>
#include<vector>
using std::vector;
int main(){
    vector<int> v{1,2,3,4,5};
    auto count=v.size();
    std::cout<<count<<std::endl;
    std::cout<<(int)nullptr<<std::endl;
    return 0;
}
