#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
	// Array of int
	Array<int>	array_int(10);
	for (int i = 0; i < array_int.size(); i++)
		array_int[i] = i + 40;
	std::cout << array_int << std::endl;

	// Array of int
	Array<std::string>	array_str(4);
	array_str[0] = "Hello";
	array_str[1] = ", ";
	array_str[2] = "World";
	try {
		array_str[30] = "!";
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << array_str << std::endl;
	return 0;
}