#include<iostream>
#include<vector>
using std::vector;

int main(){
    vector<int> v{1,2,3,4};
    for(auto item: v){
        std::cout<<item<<std::endl;
    }
    auto b=v.begin(),e=v.end();
    for(;b!=e;b++)
	std::cout<<*b<<std::endl;
    int d=7/4;
    std::cout<<d<<std::endl;
    return 0;
}    
