#pragma once
#include "Shape.h"
#include "Movable.h"

class Circle : public Shape, public Movable
{
protected:
	int radius;
	bool isCircular = true;
public:
	Circle(int x, int y, int r) {
		leftTop = Point(x, y);
		radius = r;
	}
	virtual void calculatePoints();
	virtual void calculateArea();
	virtual void calculatePerimeter();
	void move(int newX, int newY);
	void scale(float);
	string toString();
};

