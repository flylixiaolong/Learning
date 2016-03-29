#include <iostream>

class Base{
	private:
		int a=1;
	protected:
		int b=2;
	public:
		int c=3;
		void show(){
			std::cout<<a<<b<<c<<std::endl;
		}
};
class Derived:protected Base{
};

int main()
{
	Base b;
	Base *pb=&b;
	b.show();
	pb->show();
	Derived d;
	pb=&d;
	pb->show();
	return 0;
}


