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

	~Rectangle();

	friend ostream& operator<<(ostream& output, Rectangle& rect) {
		output << "Shape: Rectangle\nWidth: " << rect._width << "\nHeight: " << rect._height << "\nArea: " << rect.area << "\nPerimeter: " << rect.perimeter << "\nPoints: " + rect.pointsToString() << endl;;
		return output;
	}

	int getHeight() { return _height; }
	int getWidth() { return _width; }

	virtual void calculatePoints();
	virtual void calculateArea();
	virtual void calculatePerimeter();

	virtual void move(int, int);
	void scale(float, float);


	string toString();
};

