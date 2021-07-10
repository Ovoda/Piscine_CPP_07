#include <iostream>
#include <string>
#include "Array.hpp"

// int main(void)
// {
// 	// Array of int
// 	Array<int>	array_int(10);
// 	for (int i = 0; i < array_int.size(); i++)
// 		array_int[i] = i + 40;
// 	std::cout << array_int << std::endl;

// 	// Array of int
// 	Array<std::string>	array_str(4);
// 	array_str[0] = "Hello";
// 	array_str[1] = ", ";
// 	array_str[2] = "World";
// 	try {
// 		array_str[30] = "!";
// 	}
// 	catch (std::exception &e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	std::cout << array_str << std::endl;
// 	return 0;
// }

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}