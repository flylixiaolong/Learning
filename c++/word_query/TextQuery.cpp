#include <sstream>
#include "TextQuery.h"

using std::vector;
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::string;
using std::set;
using std::shared_ptr;
using std::cin;
using std::cout;
using std::endl;

TextQuery::TextQuery(ifstream &is):file(new vector<string>)
{
	string text;
	while (getline(is, text))
	{
		file->push_back(text);
		line_no n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line>>word)
		{
			auto &lines = wordmap[word];
			if (lines==nullptr)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wordmap.find(sought);
	if (loc==wordmap.cend())
		return QueryResult(sought,file,nodata);
	else
		return QueryResult(sought,file,loc->second);
}

ostream& operator<<(ostream &os, const QueryResult &qresult)
{
	os << qresult.sought << " occurs " << qresult.lines->size()
		<< " " << ((qresult.lines->size()<1)?"time":"times") << endl;
	for (auto num: *qresult.lines)
	{
		os << "\t(line " << num + 1 << ") "
			<< (*qresult.file)[num] << endl;
	}
	return os;
}
