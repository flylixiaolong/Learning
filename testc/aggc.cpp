#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::endl;

class Data{
    string name;
    int age=0;
    double price=0;
public:
    Data()=default;
};
int main(){
    Data item;
    cout<<sizeof(Data)<<endl;
    return 0;
}
