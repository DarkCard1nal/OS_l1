#include <iostream>
#include "Point.hpp"
#include "PointSimulator.hpp"

int main()
{
	std::cout << "Test Start!" << std::endl;

	std::cout << "class Point" << std::endl;

	Point *p = new Point(1, 2, 3, 4);

	std::cout << *p << std::endl;

	delete p;

	p = Point::RandomPoint();

	std::cout << *p << std::endl;

	delete p;

	std::cout << std::endl;
	std::cout << "class PointSimulator" << std::endl;

	PointSimulator *points = new PointSimulator(6, 0, 100);

	points->Add(new Point(1, 2, 3, 4));
	points->Add(new Point(2, 3, 4, 5));
	points->Add(new Point(6, 7, 8, 9));
	points->Add(new Point(11, 12, 13, 14));
	points->Add(new Point(15, 17, 34, 1));
	points->Add(new Point(15, 16, 17, 18));
	std::cout << *points << std::endl;
	std::cout << std::endl;

	p = points->SimulateAll();
	if (p != nullptr)
	{
		std::cout << "Last " << *p << std::endl;
	}

	points->ClearPoints();
	delete points;
	
	std::cout << "Test Stop!" << std::endl;
	return 0;
}
