#include<iostream>
namespace sp1{
    int i=0;
}
namespace sp2{
    int j=1; 
}
int i=1;
int main(){
    //using sp1::i;
    using namespace sp1; 
    std::cout<<i<<std::endl;
    //std::cout<<i<<std::endl;
    return 0;
}
