#pragma once
#include <string>
#include "Point.h";
#include <vector>

using namespace std;

class Shape
{
protected:
	double area;
	bool isCircular = false;
	Point leftTop;
	int perimeter;
	vector<Point> points{Point(0,0), Point(0,0), Point(0,0), Point(0,0)};

public:
	virtual void calculateArea();
	virtual void calculatePerimeter();
	virtual void calculatePoints();
	string toString();
};

