#include "Circle.h"

void Circle::calculatePoints() {
	Point rightBottom = Point(leftTop._x + (2*radius), leftTop._y + (2*radius));
	points = { leftTop ,rightBottom };
}

void Circle::calculateArea()
{
	area = 3.14159265*(radius^2);
}

void Circle::calculatePerimeter()
{
	perimeter = 3.14159265*radius*2;
}