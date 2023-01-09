#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

class Span {
public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	~Span();
	//Operations
	Span &operator=(const Span &rhs);
	void addNumber(int toAdd);
	template <typename InputIterator>
	void addNumber(InputIterator first, InputIterator last) {
		if (std::distance(first, last) + _vec.size() > _maxSize)
			throw SpanNoRoomException();
		_vec.insert(_vec.end(), first, last);
	}
	unsigned int shortestSpan();
	unsigned int longestSpan() const;
	//Exceptions
	class SpanNoRoomException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class SpanTooSmallException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
private:
	unsigned int _maxSize;
	std::vector<int> _vec;
};

#endif
