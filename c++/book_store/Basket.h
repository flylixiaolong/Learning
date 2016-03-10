
class Basket
{
	public:
		//Basker使用合成的默认构造函数和拷贝控制成员
		void add_item(const Quote &sale);
		{
			item.insert(std::shared_ptr<Quote>(sale.clone()));
		}
		void add_item(Quote &&sale);
		{
			item.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
		}
		double total_receipt(std::ostream&) const;
	private:
		//比较操作，用于shared_ptr,multiset成员用到
		static bool compare(const std::shared_ptr<Quote> &lhs,
				const std::shared_ptr<Quote> &rhs)
		{
			return lhs->isbn() < rhs->isbn();
		}
		//multiset保存多个报价，按照compare成员排序
		std::mutiset<shared_ptr<Quote>, decltype(compare *)>
			items(compare);
};

