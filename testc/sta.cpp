#include <iostream>

class A{
	public:
		A()=default;
		void show(){std::cout<<a<<std::endl;}
	private:
		static int a;
};

int A::a=1;
A b;

int main()
{
	A a;
	a.show();
	b.show();
	return 0;
}
