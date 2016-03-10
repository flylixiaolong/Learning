
class Bulk_quote : public Quote
{
	Bulk_quote* clone() const &
	{
		return new Bulk_Quote(*this);
	}
	Bulk_quote* clone() &&
	{
		return new Bulk_Quote(std::move(*this));
	}
};
