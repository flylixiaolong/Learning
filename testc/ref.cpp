#include<iostream>
#include<utility>

using std::cout;
using std::cin;
using std::endl;

void f1(int t, int n)
{
	t++;
	n++;
}

void f2(const int &t, const int &n)
{
	t++;
	n++;
}

void f3(int &t, int &&n)
{

}

void f4(int &&t, int &&n)
{
	t++;
	n++;
}


template<typename F, typename T, typename N>
void flip(F f, T &&t, N &&n)
{
	f(std::forward<N>(n),std::forward<T>(t));
}

void test(int &a)
{}

int main()
{
	int a=1, b=2;
	flip(f1,1,2);
	flip(f1,a,b);
	cout<<a<<' '<<b<<endl;
	f2(1,2);
	f2(a,b);
	cout<<a<<' '<<b<<endl;
	test(std::forward<int>(1));
//	flip(f2,1,2);
//	flip(f2,a,b);
//	cout<<a<<' '<<b<<endl;
//	flip(f3,1,2);
//	flip(f3,a,b);
//	cout<<a<<' '<<b<<endl;
	return 0;
}
