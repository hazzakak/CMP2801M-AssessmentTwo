#pragma once
#include "Shape.h"
#include "Movable.h"
#include <iostream>

class Circle : public Shape, public Movable
{
protected:
	float radius;
	bool isCircular = true;
public:
	Circle(int x, int y, int r) {
		leftTop = Point(x, y);
		radius = r;
	}
	friend ostream& operator<<(ostream& output, Circle& circ) {
		output << "Shape: Circle\nRadius: " << circ.radius << "\nDiameter: " << (circ.radius * 2) << "\nArea: " << circ.area << "\nPerimeter: " << circ.perimeter << "\nPoints: " << circ.pointsToString();
		return output;
	}
	virtual void calculatePoints();
	virtual void calculateArea();
	virtual void calculatePerimeter();
	void move(int newX, int newY);
	void scale(float);
	string toString();
};

