#include<iostream>

using std::cin;
using std::string;
using std::cout;
using std::endl;

int main(){
    string line;
    while(getline(cin,line)){
        cout<<line<<endl;
    }
    return 0;
}
