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
	double perimeter;
	vector<Point> points{Point(0,0), Point(0,0), Point(0,0), Point(0,0)};

public:
	virtual double calculateArea();
	virtual double calculatePerimeter();
	virtual void calculatePoints();
	string toString();
};

