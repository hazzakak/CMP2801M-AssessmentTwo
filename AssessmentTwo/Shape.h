#pragma once
#include <string>
#include "Point.h";
#include <vector>
#include <iostream>

using namespace std;

class Shape
{
protected:
	float area;
	bool isCircular = false;
	Point leftTop;
	float perimeter;
	vector<Point> points{Point(0,0), Point(0,0), Point(0,0), Point(0,0)};

public:
	void setLeftTop(Point pnt) { leftTop = pnt; }
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter();
	virtual void calculatePoints();
	string toString();
	string pointsToString();
	void operator delete(void*);
};

