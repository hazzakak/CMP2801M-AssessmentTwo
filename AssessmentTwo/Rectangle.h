#pragma once
#include "Shape.h"
#include "Movable.h"

class Rectangle : public Shape, public Movable
{
private:
	double _height;
	double _width;
public:
	double getHeight() { return _height; }
	double width() { return _width; }
	virtual void calculatePoints();
};

