#ifndef _TEXT_QUERY_H
#define _TEXT_QUERY_H 1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream &);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string,std::shared_ptr<std::set<line_no>>> wordmap;
};

class QueryResult
{
	friend std::ostream& operator<<(std::ostream &os,
			const QueryResult &qresult);
public:
    QueryResult(std::string s,
			std::shared_ptr<std::vector<std::string>> f,
			std::shared_ptr<std::set<TextQuery::line_no>> ls):
		sought(s),file(f),lines(ls){}
private:
	std::string sought;
	std::shared_ptr<std::vector<std::string>> file;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
};

#endif
