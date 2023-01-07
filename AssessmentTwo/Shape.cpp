#include "Shape.h"


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

void Shape::operator delete(void*)
{
	cout << "Shape has been deleted." << endl;
}

string Shape::toString()
{
	return "Shape";
}
