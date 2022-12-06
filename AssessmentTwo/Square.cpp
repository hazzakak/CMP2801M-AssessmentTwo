#include "Square.h"

void Square::calculatePoints() {
	Point rightTop = Point(leftTop._x + edge, leftTop._y);
	Point leftBottom = Point(leftTop._x, leftTop._y + edge);
	Point rightBottom = Point(leftTop._x + edge, leftTop._y + edge);
	points = { leftTop, rightTop,rightBottom, leftBottom };
}

void Square::calculateArea()
{
	area = edge^2;
}

void Square::calculatePerimeter()
{
	perimeter = (edge * 4);
}