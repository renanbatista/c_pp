#include "Span.hpp"

#include <limits>

Span::Span(void) {}

Span::Span(size_t N) : _N(N)
{
    this->_vec.reserve(this->_N);
}

Span::Span(Span const &copy)
{
    *this = copy;
}

Span::~Span(void) {}

Span &Span::operator=(Span const &other)
{
    if (this != &other) {
        this->_N = other._N;
        this->_vec = other._vec;
    }
    return *this;
}

void Span::addNumber(int num)
{
    if (this->_vec.size() < this->_N)
        this->_vec.push_back(num);
    else
        throw SpanIsFullError();
}

void Span::addMulti(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_vec.size() + std::distance(begin, end) <= this->_N)
        this->_vec.insert(this->_vec.begin(), begin, end);
    else
        throw SpanIsFullError();
}

int Span::shortestSpan(void)
{
    if (_vec.size() < 2)
        throw SpanIsOneOrNoneError();

    std::vector<int> sortVec = this->_vec;
    std::sort(sortVec.begin(), sortVec.end());

    int minDistance = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortVec.size(); ++i) {
        int distance = std::abs(sortVec[i] - sortVec[i - 1]);
        if (distance < minDistance)
            minDistance = distance;
    }
    return minDistance;
}

int Span::longestSpan(void)
{
    int min = *std::min_element(_vec.begin(), _vec.end());
    int max = *std::max_element(_vec.begin(), _vec.end());

    return max - min;
}

const char *Span::SpanIsFullError::what() const throw()
{
    return "ERROR: Span is full.";
}

const char *Span::SpanIsOneOrNoneError::what() const throw()
{
    return "ERROR: Span is empty or has only one element.";
}