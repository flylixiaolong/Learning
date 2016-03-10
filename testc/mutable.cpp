#include <iostream>

class A{
	private:
		mutable int a;
		mutable int b;
	public:
		A(int i,int j):a(i),b(j){}
		void setc(int i,int j) const
		{
			a=i,b=j;
			std::cout<<a<<' '<<b<<std::endl;
		}
		void setn(int i,int j)
		{
			a=i,b=j;
			std::cout<<a<<' '<<b<<std::endl;
		}
};
int main()
{
	A a(1,2);
	a.setc(3,4);
	a.setn(5,6);
	const A b(1,2);
	b.setc(3,4);
	//b.setn(5,6);
	return 0;
}
