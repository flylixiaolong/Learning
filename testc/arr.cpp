#include<iostream>
using std::cout;
using std::cin;
using std::endl;
template<unsigned T,unsigned C>
void print(const int (&array)[T][C]){
    for(const auto &row:array){
        for(const auto &column:row){
            cout<<column<<' ';
        }
        cout<<endl;
    }
}
int main(){
    int a[][3]{{2,3,4},{5,6,7},{8,9,10}};
    for(auto item:a){
        cout<<item<<' ';
    }
    cout<<endl;
    print({{2,3,4},{5,6,7},{8,9,10}});
    cout<<a[0][0]<<endl;
    cout<<"##################"<<endl;
    int b[5];
    for(int i=0;i<100;i++)
        cout<<b[i]<<endl;
    return 0;
}
