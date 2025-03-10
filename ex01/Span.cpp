#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &other) : _n(other._n), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	_n = other._n;
	_numbers = other._numbers;
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (_numbers.size() == _n)
        throw std::runtime_error("Span is full");

    _numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t count = std::distance(begin, end);
	if (_numbers.size() + count > _n)
		throw std::runtime_error("Span is full");

	// Overflow Check: Ensure adding the number won't overflow INT_MAX/INT_MIN
	for (std::vector<int>::iterator it = begin; it != end; it++)
	{
		if ((*it > 0 && *it > std::numeric_limits<int>::max()) || (*it < 0 && *it < std::numeric_limits<int>::min()))
			throw std::overflow_error("Number is out of integer range");
	}

	_numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan()
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers to calculate span");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int min = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); i++)
    {
        int diff = sorted[i] - sorted[i - 1];

        // Overflow Check: Ensure difference calculation does not overflow
        if ((sorted[i] > 0 && sorted[i - 1] < 0 && diff < 0) ||
            (sorted[i] < 0 && sorted[i - 1] > 0 && diff > 0))
        {
            throw std::overflow_error("Integer overflow detected in shortestSpan()");
        }

        if (diff < min)
            min = diff;
    }
    return min;
}

long long Span::longestSpan()
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers to calculate span");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    // Ensure non-negative difference
    return static_cast<long long>(max) - static_cast<long long>(min);
}