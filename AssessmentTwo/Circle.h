#pragma once
#include "Shape.h"
#include "Movable.h"

class Circle : public Shape, public Movable
{
protected:
	int radius;
	bool isCircular = true;
public:
	virtual void calculatePoints();
	virtual void calculateArea();
	virtual void calculatePerimeter();
	void move(int newX, int newY);
	void scale(float);
};

