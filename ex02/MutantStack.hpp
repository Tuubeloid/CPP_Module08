#pragma once

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
		typedef std::stack<T>                   stack;
			typedef typename stack::container_type  container;
			typedef typename container::iterator    iterator;

        MutantStack() : std::stack<T>() {} 
        MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}
        MutantStack<T> &operator=(const MutantStack<T> &other)
        {
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        }
        ~MutantStack() {}

        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"