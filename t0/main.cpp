#include <iostream>
#include <cstdlib>
#include "Point.hpp"
#include "PointSimulator.hpp"
#include <string>

int main(int argc, char *argv[])
{
	std::cout << "l1/t0 by Shkilnyi V. CS31!" << std::endl;
	std::string str;
	int count;

	if (argc > 1)
	{
		str = argv[1];
	}
	else
	{
		std::cout << "Enter the number of points: ";
		std::cin >> str;
	}

	count = static_cast<int>(std::strtol(str.data(), nullptr, 10));
	if (count < 1)
	{
		std::cout << "ERROR! Invalid value entered! The value must be > 0!" << std::endl;
		return 0;
	}

	PointSimulator *points = new PointSimulator(count, 0, 100);
	std::cout << "Create random points:" << std::endl;
	std::cout << *points << std::endl;
	Point *p = points->SimulateAll();
	if (p != nullptr)
	{
		std::cout << "Last " << *p << std::endl;
	}
	points->ClearPoints();
	delete points;
	return 0;
}
