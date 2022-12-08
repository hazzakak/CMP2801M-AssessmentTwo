#pragma once
#include "Shape.h"
#include "Movable.h"
#include "Rectangle.h"

class Square : public Shape, public Movable
{
private:
	float edge;
public:
	Square(int x, int y, int e) {
		edge = e;
		Shape::leftTop._x = x;
		Shape::leftTop._y = y;
	}

	friend ostream& operator<<(ostream& output, Square& sqr) {
		output << "Shape: Square\nEdge: " << sqr.edge << "\nArea: " << sqr.area << "\nPerimeter: " << sqr.perimeter << "\nPoints: " + sqr.pointsToString();
		return output;
	}

	virtual void calculatePoints();
	virtual void calculateArea();
	virtual void calculatePerimeter();

	void move(int newX, int newY);
	void scale(float scaleX);

	string toString();
};

