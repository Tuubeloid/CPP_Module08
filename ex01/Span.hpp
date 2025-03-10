#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _numbers;

	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		long long longestSpan();
};