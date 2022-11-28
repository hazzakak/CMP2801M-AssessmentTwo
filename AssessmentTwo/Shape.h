#pragma once
#include <string>
#include "Point.h";
#include <vector>

using namespace std;

class Shape
{
private:
	double area;
	bool isCircular = false;
	Point leftTop;
	double perimeter;
	vector<Point> points;

public:
	double calculateArea();
	double calculatePerimeter();
	int calculatePoints();
	string toString();
};

