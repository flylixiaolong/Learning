#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class A
{
	public:
		explicit A(int a){age=a;}
		void show(){cout<<age<<endl;}
	private:
	    int age;
};
int main()
{
	A a=3;
	a.show();
	return 0;
}
