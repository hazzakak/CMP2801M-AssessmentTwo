#include "Shape.h"

string Shape::pointsToString() {
	string ret = "";
	for (int i = 0; i < points.size(); i++) {
		ret = ret + "(" + to_string(points[i]._x) + ", " + to_string(points[i]._y) + ")";
	}
	return ret;
}

ostream& operator<<(ostream& output, Shape& shp)
{
	output << shp.toString() << endl;;
	return output;
}
