// Circle.h
#pragma once
#include "Shape.h"
#include "Movable.h"
#include <iostream>

// Circle class that inherits from Shape and Movable classes
class Circle : public Shape, public Movable
{
protected:
	float radius; // radius of the circle
	bool isCircular = true; // set isCircular to true as Circle is a circular shape
public:
	// constructor to initialize the Circle object with a center point and radius
	Circle(int x, int y, int r) {
		leftTop = Point(x, y); // set the left top point of the Circle
		radius = r; // set the radius of the Circle
	}

	// overload the stream insertion operator to output the Circle object
	friend ostream& operator<<(ostream& output, Circle& circ) {
		output << "Shape: Circle\nRadius: " << circ.radius << "\nDiameter: " << (circ.radius * 2) << "\nArea: " << circ.area << "\nPerimeter: " << circ.perimeter << "\nPoints: " << circ.pointsToString() << endl;
		return output;
	}

	// function to calculate the points of the Circle object
	virtual void calculatePoints();

	// function to calculate the area of the Circle object
	virtual void calculateArea();

	// function to calculate the perimeter of the Circle object
	virtual void calculatePerimeter();

	// function to move the Circle object to a new location
	virtual void move(int, int);

	// function to scale the Circle object
	void scale(float);

	// function to return a string representation of the Circle object
	string toString();
};