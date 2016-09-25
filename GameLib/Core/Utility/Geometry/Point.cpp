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

bool Point::operator==(const Point& other) const
	{
	return x_ == other.x() && y_ == other.y_;
	}
