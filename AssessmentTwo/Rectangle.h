#pragma once
#include "Shape.h"
#include "Movable.h"

class Rectangle : public Shape, public Movable
{
private:
	int _height;
	int _width;
public:
	Rectangle(int LTX, int LTY, int h, int w) {
		_height = h;
		_width = w;
		leftTop = Point(LTX, LTY);
	}
	int getHeight() { return _height; }
	int getWidth() { return _width; }
	virtual void calculatePoints();
	virtual void calculateArea();
	virtual void calculatePerimeter();
	void move(int newX, int newY);
	void scale(float, float);
};

