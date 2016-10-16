#ifndef POINT_H
#define POINT_H

class Point
	{
	public:
	Point() = default;
	Point(int x, int y);

	int x() const;
	int y() const;

	bool operator==(const Point& other) const;

	private:
	int x_, y_;
	};

#endif // POINT_H
