#include <iostream>

class A{
	public:
		int a;
		virtual void show()
		{
			std::cout<<a<<b<<c<<std::endl;
		}
	protected:
		int b;
		int c;
};
class B:public A{
	public:
		void set(int i,int j,int k)
		{
			a=i;
			b=j;
			c=k;
		}
};
int main()
{
	A a;
	B b;
	b.set(1,2,3);
	b.show();
	return 0;
}
