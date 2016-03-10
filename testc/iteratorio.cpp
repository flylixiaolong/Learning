#include <iostream>
#include <iterator>

int main()
{
	std::istream_iterator<int> in(std::cin),eof;
	int a;
	while(in!=eof)
	{
		a=*in++;
		std::ostream_iterator<int> os(std::cout);
		*os++=a;
		std::cout<<std::flush;
	}
	return 0;
}
