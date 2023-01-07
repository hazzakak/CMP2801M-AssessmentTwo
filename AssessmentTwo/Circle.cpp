// This file contains the implementation of the Circle class, which is derived from the Shape and Movable classes.

#include "Circle.h"
#include <iostream>

// Calculates the top left and bottom right points of the circle and stores them in the points vector.
void Circle::calculatePoints() {
	Point rightBottom = Point(leftTop._x + (2*radius), leftTop._y + (2*radius));
	points = { leftTop ,rightBottom };
}

// Calculates the area of the circle based on its radius.
void Circle::calculateArea()
{
	area = 3.14159265 * (radius * radius);
}

// Calculates the perimeter of the circle based on its radius.
void Circle::calculatePerimeter()
{
	perimeter = 3.14159265*radius*2;
}

// Moves the circle to the new (x,y) coordinates by updating the leftTop point and recalculating the points.
void Circle::move(int newX, int newY) {
	Point newLeftTop = Point(newX, newY);
	Circle::setLeftTop(newLeftTop);
	Circle::calculatePoints();
}

// Scales the circle by the given factor, updating its radius and recalculating its area, perimeter, and points.
void Circle::scale(float scaleX)
{
	Circle::radius = radius * scaleX;
	Circle::calculateArea();
	Circle::calculatePerimeter();
	Circle::calculatePoints();
}

// Returns a string representation of the Circle object, including its shape, radius, diameter, area, perimeter, and points.
string Circle::toString()
{
	return (string)"Shape: Circle\nRadius: " + to_string(radius) + "\nDiameter: " + to_string(radius * 2) + "\nArea: " + to_string(area) + "\nPerimeter: " + to_string(perimeter) + "\nPoints: " + Shape::pointsToString();
}