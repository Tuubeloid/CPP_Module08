/*A first easy exercise is the way to start off on the right foot.
Write a function template easyfind that accepts a type T. It takes two parameters.
The first one has type T and the second one is an integer.
Assuming T is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter.
If no occurrence is found, you can either throw an exception or return an error value
of your choice. If you need some inspiration, analyze how standard containers behave.
Of course, implement and turn in your own tests to ensure everything works as expected*/

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T &container, int value);

#include "easyfind.tpp"
