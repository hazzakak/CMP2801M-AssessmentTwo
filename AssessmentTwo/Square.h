#pragma once
#include "Shape.h"
#include "Movable.h"
#include "Rectangle.h"

class Square : public Shape, public Movable
{
private:
	int edge;
public:
	Square(int x, int y, int e) {
		edge = e;
		Shape::leftTop._x = x;
		Shape::leftTop._y = y;
	}
	virtual void calculatePoints();
	virtual void calculateArea();
	virtual void calculatePerimeter();
	void move(int newX, int newY);
};

