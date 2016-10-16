#ifndef RECTANGLE_H
#define RECTANGLE_H

class Point;
class Size;

class Rectangle
	{
	public:
	Rectangle(int left, int top, unsigned width, unsigned height);
	Rectangle(const Point& leftTop, const Size& size);

	int left() const;
	int top() const;
	int right() const;
	int bottom() const;

	Point letfTop() const;

	unsigned width() const;
	unsigned height() const;

	Size size() const;

	bool intersects(const Rectangle& other) const;

	private:
	int left_, top_, right_, bottom_;
	};

#endif // RECTANGLE_H
