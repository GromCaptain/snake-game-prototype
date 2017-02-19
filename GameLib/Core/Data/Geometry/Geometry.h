#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Point.h"
#include "Size.h"

class Rectangle;

enum class SizePolicy { Fixed, Scalable };

class Geometry
	{
	public:
	static Geometry fixed(const Point& position, const Size& size);
	static Geometry fixedHorizontalScalableVertical(int x, unsigned width, int yPercent, unsigned heightPercent, unsigned originalScreenHeight);
	static Geometry scalableHorizontalFixedVertical(int xPercent, unsigned widthPercent, unsigned originalScreenWidth, int y, unsigned height);
	static Geometry scalable(const Point& positionPercent, const Size& sizePercent, const Size& originalScreenSize);

	Point position() const;
	Size size() const;
	Rectangle rect() const;

	void resizeAfterScreen(const Size& screenSize);

	private:
	Geometry(SizePolicy horSizePolicy, SizePolicy vertSizePolicy, int x, int y, unsigned w, unsigned h, unsigned screenW, unsigned screenH);

	private:
	SizePolicy horizontalPolicy_, verticalPolicy_;
	int currX_, currY_;
	unsigned currW_, currH_;
	const int originalX_, originalY_;
	const unsigned originalW_, originalH_;
	const unsigned originalScreenW_, originalScreenH_;
	};

#endif // GEOMETRY_H
