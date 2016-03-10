#include <iostream>
#include <new>

using std::cin;
using std::cout;

class A{
	public:
		explicit A(int a,int b):age(a),num(b){}
	private:
		int age;
		int num;
};

int main()
{
	A *pA = new A[3]{A{1,2},A{3,4},A{5,6}};
	return 0;
}
