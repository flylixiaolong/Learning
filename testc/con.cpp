#include <iostream>
using namespace std;

class A {
    public:
        A() {cout << "A ctor" << endl;}
        virtual ~A() {cout << "A dtor" << endl;}
};

class B: public A {
    public:
        B() {cout << "B ctor" << endl;}
        ~B() {cout << "B dtor" << endl;}
        void foo(){cout << "foo" << endl;}
};

int main(){
    B *b = new B();
    b->~B();
    b->foo();
    delete b;
    return 0;
}
