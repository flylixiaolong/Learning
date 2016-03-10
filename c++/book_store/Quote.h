
class Quote
{
	public:
		virtual Quote* clone() const &
		{
			return new Quote(*this);
		}
		virtual Quote* clone() && 
		{
			return new Quote(std::move(*this));
		}
}
