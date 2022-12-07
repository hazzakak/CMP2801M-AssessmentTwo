#include "Square.h"

void Square::calculatePoints() {
	Point rightTop = Point(leftTop._x + edge, leftTop._y);
	Point leftBottom = Point(leftTop._x, leftTop._y + edge);
	Point rightBottom = Point(leftTop._x + edge, leftTop._y + edge);
	points = { leftTop, rightTop,rightBottom, leftBottom };
}

void Square::calculateArea()
{
	area = edge*edge;
}

void Square::calculatePerimeter()
{
	perimeter = (edge * 4);
}

void Square::move(int newX, int newY) {
	Point newLeftTop = Point(newX, newY);
	Square::setLeftTop(newLeftTop);
	Square::calculatePoints();
}

void Square::scale(float scaleX)
{
	Square::edge = edge * scaleX;
	Square::calculateArea();
	Square::calculatePerimeter();
	Square::calculatePoints();

}

string Square::toString()
{
	return (string)"Shape: Square\nEdge: " + to_string(edge) + "\nArea: " + to_string(area) + "\nPerimeter: " + to_string(perimeter) + "\nPoints: " + Shape::pointsToString();
}