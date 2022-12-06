#include "Rectangle.h"


void Rectangle::calculatePoints() {
	Point rightTop = Point(leftTop._x + _width, leftTop._y);
	Point leftBottom = Point(leftTop._x, leftTop._y + _height);
	Point rightBottom = Point(leftTop._x + _width, leftTop._y + _height);
	points = { leftTop, rightTop,rightBottom, leftBottom };
}

void Rectangle::calculateArea()
{
	area = _width * _height;
}

void Rectangle::calculatePerimeter()
{
	perimeter = (_width * 2) + (_height * 2);
}
