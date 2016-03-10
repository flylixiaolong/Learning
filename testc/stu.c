#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main(){
    string str1="fly";
    char str2[]="fly";
    cout<<str1.size()<<endl;
    cout<<strlen(str1.c_str())<<endl;
    cout<<strlen(str2)<<endl;
    return 0;
}
