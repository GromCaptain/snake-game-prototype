#include "Rectangle.h"

#include "Point.h"
#include "Size.h"

Rectangle::Rectangle(int left, int top, unsigned width, unsigned height):
	left_(left), top_(top), right_(left + width), bottom_(top + height)
	{
	}

Rectangle::Rectangle(const Point& leftTop, const Size& size):
	Rectangle(leftTop.x(), leftTop.y(), size.width(), size.height())
	{
	}

int Rectangle::left() const
	{
	return left_;
	}
int Rectangle::top() const
	{
	return top_;
	}
int Rectangle::right() const
	{
	return right_;
	}
int Rectangle::bottom() const
	{
	return bottom_;
	}

Point Rectangle::letfTop() const
	{
	return { left_, top_ };
	}

unsigned Rectangle::width() const
	{
	return right_ - left_;
	}
unsigned Rectangle::height() const
	{
	return bottom_ - top_;
	}

Size Rectangle::size() const
	{
	return { width(), height() };
	}

bool Rectangle::intersects(const Rectangle& other) const
	{
	bool xIntersects = !(left_ > other.right_ || right_ < other.left_);
	bool yIntersects = !(top_ > other.bottom_ || bottom_ < other.top_);
	return xIntersects && yIntersects;
	}

