#include<iostream>
#include<cstddef>
using std::cout;
using std::cin;
using std::endl;

//返回局部变量的指针
//func1是一个函数，该函数返回一个指向含有三个元素的数组的指正
int (*func1(int a[3][3]))[3]{
    int (*p)[3]=a;
    return p;
}
//参数数组维度可变
template<unsigned N,unsigned M>
int (*func3(int (&a)[N][M]))[M]{
    return a;
}
//参数数组维度可变
template<unsigned M>
int (*func4(int (*a)[M]))[M]{
    return a;
}
//参数数组维度可变
template<unsigned N,unsigned M>
auto func5(int (&a)[N][M]) -> int(*)[M]{
    return a;
}
//返回局部变量的指针
int *func2(){
    int a=10;
    int *p=&a;
    return p;
}
int main(){
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int (*p)[3]=func1(a);
    int *pi=(int*)p;
    cout<<pi[0]<<','<<pi[1]<<','<<pi[2]<<','<<pi[3]<<','<<pi[5]<<','<<pi[6]<<','<<pi[7]<<','<<pi[8]<<endl;
    //cout<<"指向三个元素的数组"<<endl;
    cout<<pi[0]<<','<<pi[1]<<','<<pi[2]<<endl;
    int *p2=func2();
    int b[2][3]={{1,2,3},{4,5,6}};
    func3(b);
    func3(a);
    func4(b);
    func5(b);
    func5(a);
    int (*c)[3]=func4(a);
    cout<<*p2<<endl;
    cout<<*p2<<endl;
    return 0;
} 
