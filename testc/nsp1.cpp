#include<iostream>
namespace std{
    int max(int a,int b){
        return a>b?a:b;
    }
}
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    using std::max;
    //using namespace std;
    std::cout<<max(1,2)<<std::endl;
    return 0;
}
