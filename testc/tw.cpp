#include <iostream>

class A{
	public:
		A(int a,int b,int c):aa(a),bb(b),cc(c){std::cout<<3<<std::endl;}
		A():A(0,0,0){std::cout<<0<<std::endl;}
		A(int a):A(a,1,1){std::cout<<1<<std::endl;}
		A(int a,int b):A(a,b,2){std::cout<<2<<std::endl;}
	private:
	    int aa,bb,cc;
};
int main()
{
	A();
	A(1);
	A(2,2);
	A(3,3,3);
	return 0;
}
