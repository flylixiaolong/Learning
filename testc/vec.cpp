#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::string;
namespace mysp{
    struct Node{
        int a=20;
        std::string s="lixiaologn"; 
    };
    void pt(struct Node p);
    namespace {
        int i;
    }
}
void mysp::pt(struct mysp::Node p){
    std::cout<<p.a<<std::cout<<p.s<<std::endl;
}
int main(){
    vector<string> v;
    string s; 
    while(std::cin>>s){
        v.push_back(s);
    }
    for(auto a:v){
        std::cout<<a<<std::endl;
    }
    struct mysp::Node p;
    mysp::pt(p);
    vector<string> v2=v;
    v[0]="hle";
    for(auto a:v2){
        std::cout<<a<<std::endl;
    }
    return 0;
}
