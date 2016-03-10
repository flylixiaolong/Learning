#include <iostream>
#include <algorithm>
#include "Basket.h"

using std::endl;

double Basker::total_receipt(ostream &os) const
{
	double sum=0.0;
	for(auto iter = items.cbegin();
			iter != items.cend();
			iter = item.upper_bound(*iter))
	{
		sum += print_total(os, **iter,items.count(*iter));
	}
	os << "Total Sale: " << sum <<endl;
	return sum;
}
