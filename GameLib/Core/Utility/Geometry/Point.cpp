#include "Point.h"

Point::Point(int x, int y):
	x_(x), y_(y)
	{
	}

int Point::x() const
	{
	return x_;
	}

int Point::y() const
	{
	return y_;
	}
