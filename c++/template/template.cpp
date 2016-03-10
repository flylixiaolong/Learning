#include <iostream>

using std::endl;
using std::cout;

template <typename> class B;
template <typename> class A;
template <typename T>
	bool operator==(const A<T> &,const A<T> &);
template <typename T>
class A
{
	friend class B<T>;
	friend bool operator==<T>(const A &la,const A &ra);
private:
	int a=0;
	int b=1;
};

template <typename T>
bool operator==(const A<T> &la,const A<T> &rb)
{
	if(la.a==rb.a && la.b==rb.b)
		return true;
	else
		return false;
}

template <typename T>
class B
{
public:
	void show(const A<T> &a)
	{
		cout<<a.a<<' '<<a.b<<endl;
	}
};
int main()
{
	A<int> a1,a2;
	cout<<(a1==a2)<<endl;
	B<int> b;
	b.show(a1);
	return 0;
}
