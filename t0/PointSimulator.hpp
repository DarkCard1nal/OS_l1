#pragma once
#ifndef POINT_SIMULATOR_H
#define POINT_SIMULATOR_H

#include <iostream>
#include <vector>
#include <ostream>
#include "Point.hpp"

class PointSimulator
{
public:
	PointSimulator();
	PointSimulator(int randomCount, int min = 0, int max = 1000);
	PointSimulator(std::vector<Point *>);
	~PointSimulator();

	void Add(Point *);
	const int Count() const;
	Point *SimulateAll();
	void ClearPoints();
	const std::vector<Point *> GetPoints() const;
	friend std::ostream &operator<<(std::ostream &, const PointSimulator &);

private:
	std::vector<Point *> _points;

	int Simulate();
	Point *FindNeighbor(const Point *);
};

#endif // POINT_SIMULATOR_H
