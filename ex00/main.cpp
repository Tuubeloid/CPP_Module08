#include "easyfind.hpp"
#include <vector>

int main() {
    std::vector<int> vec;
	int find = 42;
	int find2 = 100;
	int find3 = 10;
	int find4 = 0;
    vec.push_back(10);
    vec.push_back(42);
    vec.push_back(100);

    try {
        std::vector<int>::iterator it = easyfind(vec, find);
        std::cout << "Found: " << *it << std::endl;
		std::vector<int>::iterator it2 = easyfind(vec, find2);
        std::cout << "Found: " << *it2 << std::endl;
	    std::vector<int>::iterator it3 = easyfind(vec, find3);
        std::cout << "Found: " << *it3 << std::endl;
		std::vector<int>::iterator it4 = easyfind(vec, find4);
        std::cout << "Found: " << *it4 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::vector<int> vec2;
	int find5 = 42;

	try {
		std::vector<int>::iterator it5 = easyfind(vec2, find5);
		std::cout << "Found: " << *it5 << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}