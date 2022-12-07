#pragma once
#include <string>
using namespace std;

class Point
{
public:
	int _x;
	int _y;
	Point(int x, int y) {
		_x = x;
		_y = y;
	}

	Point() {
		_x = 0;
		_y = 0;
	}
};

