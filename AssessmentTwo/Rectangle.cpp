#include "Rectangle.h"
#include <format>

Rectangle::~Rectangle()
{
	cout << "Rectangle has been deleted" << endl;
}

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

void Rectangle::move(int newX, int newY) {
	Point newLeftTop = Point(newX, newY);
	Rectangle::setLeftTop(newLeftTop);
	Rectangle::calculatePoints();
}

void Rectangle::scale(float scaleX, float scaleY)
{
	Rectangle::_width = _width * scaleX;
	Rectangle::_height = _height * scaleY;
	Rectangle::calculateArea();
	Rectangle::calculatePerimeter();
	Rectangle::calculatePoints();

}

string Rectangle::toString()
{
	return (string)"Shape: Rectangle\nWidth: " + to_string(_width) + "\nHeight: " + to_string(_height) + "\nArea: " + to_string(area) + "\nPerimeter: " + to_string(perimeter) + "\nPoints: " + Shape::pointsToString();
}
