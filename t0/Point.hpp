#pragma once
#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <random>
#include <ostream>

class Point
{
public:
	Point(int, int, int, int);

	void AbsorbMass(Point *);
	int X() const;
	int Y() const;
	int Z() const;
	int Mass() const;
	static Point *RandomPoint(int min = 0, int max = 1000);
	static double Distance(const Point *, const Point *);
	friend std::ostream &operator<<(std::ostream &, const Point &);

private:
	int _x;
	int _y;
	int _z;
	int _mass;
};

#endif // POINT_H
