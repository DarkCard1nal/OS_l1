#include "Point.hpp"

Point::Point(int x, int y, int z, int mass)
{
	_x = x;
	_y = y;
	_z = z;
	_mass = mass;
}

void Point::AbsorbMass(Point *oldPoint)
{
	_mass += oldPoint->Mass();

	delete oldPoint;
	oldPoint = nullptr;
}

int Point::X() const
{
	return _x;
}

int Point::Y() const
{
	return _y;
}

int Point::Z() const
{
	return _z;
}

int Point::Mass() const
{
	return _mass;
}

Point *Point::RandomPoint(int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);

	return new Point(dis(gen), dis(gen), dis(gen), dis(gen));
}

double Point::Distance(const Point *a, const Point *b)
{
	return std::sqrt(std::pow(b->X() - a->X(), 2) +
		std::pow(b->Y() - a->Y(), 2) +
		std::pow(b->Z() - a->Z(), 2));
}

std::ostream &operator<<(std::ostream &os, const Point &point)
{
	os << "Point(x: " << point.X() << ", y: " << point.Y() << ", z: " << point.Z() << ", mass: " << point.Mass() << ")";
	return os;
}