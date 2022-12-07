#include "Shape.h"

void Shape::calculateArea()
{
}

void Shape::calculatePerimeter()
{
}

void Shape::calculatePoints()
{
}

string Shape::pointsToString() {
	string ret = "";
	for (int i = 0; i < points.size(); i++) {
		ret = ret + "(" + to_string(points[i]._x) + ", " + to_string(points[i]._y) + ")";
	}
	return ret;
}

string Shape::toString()
{
	return "Shape";
}
