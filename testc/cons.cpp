#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class A{
	public:
		A(int i):num(i){}
		//void show(){cout<<num<<endl;}
		void show() const {cout<<num<<endl;}
	private:
		int num;
};

int main()
{
	A a(10);
	const A b(11);
	a.show();
	b.show();
	return 0;
}
