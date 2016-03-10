#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

template<typename> class C;
template<typename T>
class A
{
	friend class B;
	friend class C<T>;
	template<typename X> friend class D;
public:
	A(T la,T rb):a(la),b(rb){}
private:
	T a;
	T b;
};

class B
{
public:
	template<typename T>
	void show(const A<T> &ra)
	{
		cout<<ra.a<<' '<<ra.b<<endl;
	}
};

template<typename T>
class C
{
public:
	void show(const A<T> &ra)
	{
		cout<<ra.a<<' '<<ra.b<<endl;
	}
};

template<typename T>
class D
{
public:
    template<typename C>
	void show(const A<C> &ra)
	{
		cout<<ra.a<<' '<<ra.b<<endl;
	}
};

int main()
{
	A<int> a1(1,2);
	A<string> a2("hello"," word!");
	B b;
	b.show(a1);
	b.show(a2);
	C<int> c1;
	C<string> c2;
	c1.show(a1);
	c2.show(a2);
	D<int> d1;
	D<string> d2;
	d1.show(a1);
	d1.show(a2);
	d2.show(a1);
	d2.show(a2);
	return 0;
}
