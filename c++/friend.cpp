#include <iostream>

class A{
	friend void show(const A &a);
	private:
		int a=1;
	protected:
		int b=2;
	public:
		int c=3;
};
void show(const A &a)
{
	std::cout<<a.a<<a.b<<a.c<<std::endl;
}
int main()
{
	A a;
	show(a);
	return 0;
}

