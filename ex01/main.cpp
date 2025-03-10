#include "Span.hpp"
#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>

void testBasic()
{
    std::cout << "=== Basic Test ===" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testEdgeCases()
{
    std::cout << "\n=== Edge Cases ===" << std::endl;
    try
    {
        Span emptySpan(0);
        std::cout << "Shortest Span (empty): " << emptySpan.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Span singleSpan(1);
        singleSpan.addNumber(42);
        std::cout << "Shortest Span (single element): " << singleSpan.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4); // Should throw
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception on overfilling: " << e.what() << std::endl;
    }
}

void testLargeSpan()
{
    std::cout << "\n=== Large Span Test ===" << std::endl;
    Span sp(10000);
    std::vector<int> v(10000);
    for (int i = 0; i < 10000; i++)
        v[i] = i * 2; // Ensuring non-duplicate values

    sp.addNumbers(v.begin(), v.end());
    std::cout << "Shortest Span (should be 2): " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testNegativeAndLargeValues()
{
    std::cout << "\n=== Negative & Large Values Test ===" << std::endl;
    Span sp(6);
    sp.addNumber(-1000);
    sp.addNumber(5000);
    sp.addNumber(2000);
    sp.addNumber(0);
    sp.addNumber(-500);
    sp.addNumber(std::numeric_limits<int>::max());

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testDuplicates()
{
    std::cout << "\n=== Duplicates Test ===" << std::endl;
    Span sp(5);
    sp.addNumber(10);
    sp.addNumber(10);
    sp.addNumber(10);
    sp.addNumber(10);
    sp.addNumber(10);

    std::cout << "Shortest Span (should be 0): " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span (should be 0): " << sp.longestSpan() << std::endl;
}

void stressTest()
{
    std::cout << "\n=== Stress Test (100,000 elements) ===" << std::endl;
    Span sp(100000);
    std::vector<int> v(100000);
    std::srand(std::time(0));

    for (size_t i = 0; i < 100000; i++)
        v[i] = std::rand();

    sp.addNumbers(v.begin(), v.end());
    
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

int main()
{
    testBasic();
    testEdgeCases();
    testLargeSpan();
    testNegativeAndLargeValues();
    testDuplicates();
    stressTest();

    return 0;
}