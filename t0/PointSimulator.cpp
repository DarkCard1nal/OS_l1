#include "PointSimulator.hpp"

PointSimulator::PointSimulator()
{
}

PointSimulator::PointSimulator(int randomCount, int min, int max)
{
	for (int i = 0; i < randomCount; i++)
	{
		Add(Point::RandomPoint(min, max));
	}
}

PointSimulator::PointSimulator(std::vector<Point *> points)
{
	_points = points;
}

PointSimulator::~PointSimulator()
{
	ClearPoints();
}

void PointSimulator::Add(Point *point)
{
	_points.push_back(point);
}

const int PointSimulator::Count() const
{
	return _points.size();
}

Point *PointSimulator::SimulateAll()
{
	if (_points.empty())
	{
		return nullptr;
	}

	std::cout << "Start Point SimulateAll, Total points: " << Count() << std::endl;

	for(int i = 1; Count() > 1; i++)
	{
		std::cout << "Iteration: " << i << std::endl;
		std::cout << "Point Count: " << Simulate() << std::endl;
		std::cout << *this << std::endl;
	}
	
	std::cout << "Stop Point SimulateAll" << std::endl;

	return _points.front();
}

void PointSimulator::ClearPoints()
{
	for (Point *point : _points)
	{
		delete point;
	}
	_points.clear();
}

const std::vector<Point *> PointSimulator::GetPoints() const
{
	return _points;
}

int PointSimulator::Simulate()
{
	if (Count() < 2)
	{
		return Count();
	}

	auto it = std::min_element(_points.begin(), _points.end(), [](Point *p1, Point *p2)
		{
			return p1->Mass() < p2->Mass();
		});

	Point *p = new Point(**it);
	_points.erase(it);
	FindNeighbor(p)->AbsorbMass(p);

	return Count();
}

Point *PointSimulator::FindNeighbor(const Point *a)
{
	if (_points.empty())
	{
		return nullptr;
	}

	auto it = std::min_element(_points.begin(), _points.end(), [a](Point *p1, Point *p2)
		{
			return Point::Distance(a, p1) < Point::Distance(a, p2);
		});

	return *it;
}

std::ostream &operator<<(std::ostream &os, const PointSimulator &points)
{
	for (Point *point : points.GetPoints())
	{
		os << *point << std::endl;
	}
	return os;
}
