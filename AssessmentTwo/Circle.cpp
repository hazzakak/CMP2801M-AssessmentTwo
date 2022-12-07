#include "Circle.h"

void Circle::calculatePoints() {
	Point rightBottom = Point(leftTop._x + (2*radius), leftTop._y + (2*radius));
	points = { leftTop ,rightBottom };
}

void Circle::calculateArea()
{
	area = 3.14159265*(radius*radius);
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

string Circle::toString()
{
	return (string)"Shape: Circle\nRadius: " + to_string(radius) + "\nDiameter: " + to_string(radius*2) + "\nArea: " + to_string(area) + "\nPerimeter: " + to_string(perimeter) + "\nPoints: " + Shape::pointsToString();
}
