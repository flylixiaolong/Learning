#include<iostream>
using namespace std;

class A{
private:
    int a;
    int b;
public:
    A(int a,int b){
        this->a=a;
	this->b=b;
        cout<<"hello base A"<<endl;
        cout<<a<<'-'<<b<<endl;
    }
    virtual void show(){
        cout<<"hello my name is a"<<endl;
    }
};
class D:public A{
public:
    D(int a,int b):A(a,b){
        cout<<"hello base A"<<endl;
        cout<<a<<'-'<<b<<endl;
    }
    void show(){
        cout<<"hello my name is d"<<endl;
    }
};
class E:public A{
public:
    E(int a,int b):A(a,b){
        cout<<"hello base A"<<endl;
        cout<<a<<'-'<<b<<endl;
    }
    void show(){
        cout<<"hello my name is e"<<endl;
    }
};
class B{
private:
    int c;
    int d;
public:
    B(int c,int d){
        this->c=c;
	this->d=d;
        cout<<"hello base B"<<endl;
        cout<<c<<'-'<<d<<endl;
    }
    void show(){
        cout<<"hello my name is b"<<endl;
    }
};
class C:public A,public B{
private:
    int e;
public:
    C(int a,int b, int c,int d,int f):A(a,b),B(c,d),e{f}{
    cout<<"hello drive C"<<endl;
    cout<<"C.e="<<e<<endl;
    }
    void show(){
        cout<<"hello my name is c"<<endl;
    }
};
int main()
{
    A a=A(1,2);
    B b=B(3,4);
    C c=C(1,2,3,4,5);
    D d=D(1,2);
    E e=E(3,4);
    A *p;
    p=&d;
    p->show();
    p=&e;
    p->show();
    const int &i=1; 
    cout<<i<<endl;
    cout<<"#######################"<<endl;
    A f(10,11);
    struct Dog {
       int age;
       int eat;
    };
    Dog dog=Dog();
    cout<<dog.age<<dog.eat<<endl;
    A h{1,2};
    h={3,4};
    h.show();
}
