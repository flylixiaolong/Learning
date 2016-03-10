#include <iostream>
#include <string>
#include <fstream>
#include "TextQuery.h"

using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[])
{
	ifstream input(argv[1]);
	TextQuery tq = TextQuery(input);
	QueryResult qr = tq.query(argv[2]);
	cout<<qr<<endl;
	return 0;
}
