#include "MutantStack.hpp"
#include <iostream>
#include <list>

template <typename T>
void testContainer(T &container)
{
    container.push_back(5);
    container.push_back(17);
    std::cout << container.back() << std::endl;
    container.pop_back();
    std::cout << container.size() << std::endl;
    container.push_back(3);
    container.push_back(5);
    container.push_back(737);
    container.push_back(0);

    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
std::list<int> lst;
testContainer(lst);

MutantStack<int> mstack2;
mstack2.pop();

return 0;
}
