#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int *p=new int;
	*p=12;
	cout<<*p<<'a'<<endl;
	delete p;
	cout<<*p<<'b'<<endl;
	if(p==nullptr)
	    cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	p=nullptr;
	if(p==nullptr)
	    cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	delete p;
	if(p==nullptr)
	    cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	delete p;
	if(p==nullptr)
	    cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}
