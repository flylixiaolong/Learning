#ifndef _QUERY_H
#define _QUERY_H 1

#include "TextQuery.h"

class QueryBase {
	friend class Query;
protectected:
	using line_no = TextQuery::line_no;
	virtual ~QueryBase() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;
};

class Query
{
	friend Query Operator~(const Query &);
	friend Query Operator|(const Query&, const Query&);
	friend Query Operator&(const Query&, const Query&);
public:
	Query(const std::string&);
	QueryResult eval(const TextQuery&t) const
	{
		return q->eval(t);
	}
	std::string rep() const
	{
		return q->rep();
	}
private:
	Query(std::shared_ptr<QueryBase> query):q(query){}
	std::shared_ptr<QueryBase> q;
};

class WordQuery: public QueryBase
{
	friend class Query;
	WordQuery(const std::string &s):query_word(s){}
	QueryResult eval(const TextQuery &t) const
	{
		return t.query(query_word);
	}
	std::string rep() const
	{
		return query_word;
	}
	std::string query_word;
}

inline Query::Query(const std::string &s): q(new WordQuery(s)){}

class NotQuery: public QueryBase
{
	friend Query Operator~(const Query &);
	NotQuery(const Query &q): query(q){}
	std::string rep() const 
	{
		return "~(" + query.rep() + ")";
	}
	QueryResult eval(const TextQuery&) const;
	Query query;
};
inline Query operator~(const Query &operand)
{
	return std::shared_ptr<QueryBase>(new NotQuery(operand));
}

class BinaryQuery: public QueryBase
{
protected:
	BinaryQuery(const Query &l,const Query &r, std::string):
		lhs(l),rhs(r),op_sym(s){}
	std::string rep() const
	{
		return "(" + lhs.rep() + " "
			+ op_sym + " "
			+ rhs.rep() + ")";
	}
	Query lhs, rhs;
	std::string op_sym;
};


class AndQuery: public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right):
		BinaryQuery(left,right,'&'){}
	QueryResult eval(const TextQuery&) const;
};
inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<QueryBase>(new AndQuery(lhs,rhs));
}

class OrQuery: public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right):
		lhs(left),rhs(right),op_sym('|'){}
	QueryResult eval(const TextQuery&) const;
}
inline Query Operator&(const Query &lhs, const Query &rhs)
{
	return std::shared<QueryBase>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery &Text) const
{
	auto right = rhs.eval(text),left = lhs.eval(text);
	auto ret = make_shared<set<line_no>>(left.begin(),left.end());
	ret->insert(right.begin(),right.end());
	return QueryResult(rep(), ret, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &Text) const
{
	auto right = rhs.eval(text),left = lhs.eval(text);
	auto ret = make_shared<set<line_no>>();
	set_intersection(left.begin(), left.end(),
			right.begin(), right.end(),
			inserter(*ret, ret->begin()));
	return QueryResult(rep(), ret, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &Text) const
{
	auto result = query.eval(text);
	auto ret = make_shared<set<line_no>>();
	auto begin=result.begin(), end=result.end();
    auto size=result.get_file()->size();
	for (size_t n=0; n!=size; ++n)
	{
		if(begin!=end || *begin!=n)
			ret->insert(n);
		else
			if(begin!=end)
				++begin;
	}
	return QueryResult(rep(), ret, result.get_file());
}

#endif
