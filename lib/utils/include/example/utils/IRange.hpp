#pragma once
#include <iterator>

namespace example
{
	template<typename Iterator>
	class IteratorRange
	{
		public:
		IteratorRange(Iterator&& b, Iterator&& e): b(std::move(b)), e(std::move(e))
		{
		}
		[[nodiscard]] Iterator& begin() { return b; }
		[[nodiscard]] Iterator& end() { return e; }

		private:
		Iterator b;
		Iterator e;
	};

	template<typename IType>
	class IRangeIterator
	{
		public:
		using __iterator_category = std::input_iterator_tag;
		using value_type = IType;
		using difference_type = IType;
		using pointer = IType*;
		using reference = IType&;

		explicit IRangeIterator(IType current = 0): current(current) {}
		[[nodiscard]] bool operator==(const IRangeIterator& other) const
		{
			return current == other.current;
		}
		[[nodiscard]] bool operator!=(const IRangeIterator& other) const
		{
			return current != other.current;
		}
		[[nodiscard]] reference operator*() const { return current; }
		[[nodiscard]] reference operator*() { return current; }
		[[nodiscard]] pointer operator->() const { return &current; }
		[[nodiscard]] pointer operator->() { return &current; }
		[[nodiscard]] IRangeIterator operator++(int)	// NOLINT
		{
			auto copy = *this;
			++(*this);
			return copy;
		}
		[[nodiscard]] IRangeIterator& operator++()	// NOLINT
		{
			current++;
			return *this;
		}

		private:
		IType current;
	};

	template<typename IType>
	IteratorRange<IRangeIterator<IType>> irange(IType begin, IType end)
	{
		return IteratorRange(IRangeIterator(begin), IRangeIterator(end));
	}

	template<typename IType>
	IteratorRange<IRangeIterator<IType>> irange(IType end)
	{
		return IteratorRange(IRangeIterator<IType>(0), IRangeIterator(end));
	}
}	 // namespace example
