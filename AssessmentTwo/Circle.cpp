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

void Circle::move(int newX, int newY) {
	Point newLeftTop = Point(newX, newY);
	Circle::setLeftTop(newLeftTop);
	Circle::calculatePoints();
}

void Circle::scale(float scaleX)
{
	Circle::radius = radius * scaleX;
	Circle::calculateArea();
	Circle::calculatePerimeter();
	Circle::calculatePoints();
}
