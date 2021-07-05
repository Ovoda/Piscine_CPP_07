#include <iostream>
#include <string>
#include "Iter.hpp"
#include "Unit.hpp"

void fun(int *elem)
{
	std::cout << *elem << std::endl;
}

void fun(Unit *elem)
{
	std::cout << *elem;
}

int main(void)
{
	int arr[] = {42, 43, 44, 45, 46, 47};
	Unit units[] = {Unit("Warrior"), Unit("Archer"), Unit("Mage")};

	Iter<int>(arr, 5, &fun);
	Iter<Unit>(units, 3, &fun);

	return 0;
}