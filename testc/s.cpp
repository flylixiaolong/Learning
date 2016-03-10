#include<iostream>
using namespace std;

struct Test1
{
    Test1() // 无参构造函数
    { 
        cout << "Construct Test1" << endl ;
    }

    Test1(const Test1& t1) // 拷贝构造函数
    {
        cout << "Copy constructor for Test1" << endl ;
        this->a = t1.a ;
    }

    Test1& operator = (const Test1& t1) // 赋值运算符
    {
        cout << "assignment for Test1" << endl ;
        this->a = t1.a ;
        return *this;
    }

    int a ;
};

struct Test2
{
    Test1 test1 ;
    Test2(Test1 &t1):test1(t1)
    {
        cout <<"lalala!"<<endl;
    }
};

int func(){
    static int i=0;
    cout<<"#"<<endl;
    return i++;
}; 
int *func1(){
    static int a[4]={1,2,3,4};
    for(int i=0;i<4;i++){
        cout<<"a["<<i<<"]="<<a[i]<<endl;
        a[i]++;
    }
    cout<<"#"<<&a<<endl;
    return a;
}
int main(){
//    Test1 t1;
//    Test2 t2(t1) ;
//    
//    int a[3]={1,2,3};
//    int (&b)[3]=a;
//    int *p=a;
//    int *(&c)=p;
//    cout<<a[0]<<a[1]<<a[2]<<endl;
//    cout<<*c<<*(c+1)<<*(c+2)<<endl;
//    int d[2][3]={1,2,3,3,4,5};
//    int (*fp)[3]=d;
//    cout<<fp[0][0]<<endl;
//    cout<<fp[1][0]<<endl;
//    cout<<"#############################"<<endl;
//    int (*fun[4])()={&func,&func,&func,&func};
//    for(int i=0;i<4;i++){
//        cout<<func()<<endl;
//    }
//    cout<<*func1()<<endl;
//    cout<<"############################"<<endl;
    int *(*fun1)()=&func1;
    cout<<&fun1()[0]<<endl<<fun1()[3]<<fun1()[2]<<fun1()[1]<<fun1()[0]<<endl;
    cout<<&fun1()[0]<<endl<<fun1()[0]<<fun1()[1]<<fun1()[2]<<fun1()[3]<<endl;
    double fd=1.23;
    const int &a=fd;
    cout<<a; 
    const int p1=2;
    const int * const p2 = &p1;
    int *null = 0, *ss=null;
    return 0;
}
