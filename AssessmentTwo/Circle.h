#pragma once
#include "Shape.h"
#include "Movable.h"

class Circle : public Shape, public Movable
{
private:
	double radius;
	bool isCircular = true;
};

