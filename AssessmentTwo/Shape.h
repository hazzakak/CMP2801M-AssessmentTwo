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
	virtual double calculateArea();
	virtual double calculatePerimeter();
	virtual int calculatePoints();
	string toString();
};

