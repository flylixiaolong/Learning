#include <iostream>

typedef double money;
class Account{
	typedef double money;
	public:
		money balance(){return bal;}
	private:
		money bal = 10.0;
};
int main()
{
    Account a;
	std::cout<<a.balance()<<std::endl;
	return 0;
}

