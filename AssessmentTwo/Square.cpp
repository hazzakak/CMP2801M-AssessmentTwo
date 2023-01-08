#include "Square.h"

Square::~Square()
{
	cout << "Square has been deleted" << endl;
}

// Calculates the points of the square based on its left top point and edge length
void Square::calculatePoints() {
	Point rightTop = Point(leftTop._x + edge, leftTop._y); // right top point is left top point + edge on the x-axis
	Point leftBottom = Point(leftTop._x, leftTop._y + edge); // left bottom point is left top point + edge on the y-axis
	Point rightBottom = Point(leftTop._x + edge, leftTop._y + edge); // right bottom point is left top point + edge on both x and y-axis
	points = { leftTop, rightTop,rightBottom, leftBottom }; // set points vector
}

// Calculates the area of the square based on its edge length
void Square::calculateArea()
{
	area = edge * edge;
}

// Calculates the perimeter of the square based on its edge length
void Square::calculatePerimeter()
{
	perimeter = (edge * 4);
}

// Moves the square to a new position based on new x and y coordinates
void Square::move(int newX, int newY) {
	Point newLeftTop = Point(newX, newY); // create a new left top point with the new x and y coordinates
	Square::setLeftTop(newLeftTop); // set the new left top point
	Square::calculatePoints(); // calculate the new points of the square based on the new left top point
}

// Scales the square based on a given scale factor for the x-axis
void Square::scale(float scaleX)
{
	Square::edge = edge * scaleX; // update edge length with scale factor
	Square::calculateArea(); // update area
	Square::calculatePerimeter(); // update perimeter
	Square::calculatePoints(); // update points
}

// Returns a string representation of the square
string Square::toString()
{
	return (string)"Shape: Square\nEdge: " + to_string(edge) + "\nArea: " + to_string(area) + "\nPerimeter: " + to_string(perimeter) + "\nPoints: " + Shape::pointsToString();
}