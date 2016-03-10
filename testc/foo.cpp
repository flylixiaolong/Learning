#include <iostream>

class Foo{
	public:
		Foo(int i=0):num(i){}
		Foo &operator=(const Foo&) &;
		Foo &retFoo();
		Foo retVal();
		void show(){std::cout<<num<<std::endl;}
	private:
		int num;
};
Foo &Foo::operator=(const Foo&rhs) &
{
    num=rhs.num;
	return *this;
}
Foo &Foo::retFoo()
{
	return *this;
}
Foo Foo::retVal()
{
	return *this;
}

int main()
{
	Foo i(1),j(2),k(3);
	std::cout<<"-----------------"<<std::endl;
	i.show();
	j.show();
	std::cout<<"-----------------"<<std::endl;
	i=j;
	i.show();
	j.show();
	std::cout<<"-----------------"<<std::endl;
	i.retFoo()=j;
	i.show();
	j.show();
	std::cout<<"-----------------"<<std::endl;
	i=k.retVal();
	i.show();
	j.show();
	std::cout<<"-----------------"<<std::endl;
	return 0;
}
