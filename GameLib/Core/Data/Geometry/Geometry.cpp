#include "Geometry.h"

Geometry Geometry::fixed(const Point& position, const Size& size)
	{
	return Geometry(SizePolicy::Fixed, SizePolicy::Fixed, position.x(), position.y(), size.width(), size.height(), 0, 0);
	}

Geometry Geometry::fixedHorizontalScalableVertical(int x, unsigned width, int yPercent, unsigned heightPercent, unsigned originalScreenHeight)
	{
	int y = originalScreenHeight * yPercent / 100;
	unsigned height = originalScreenHeight * heightPercent / 100;
	return Geometry(SizePolicy::Fixed, SizePolicy::Scalable, x, y, width, height, 0, originalScreenHeight);
	}

Geometry Geometry::scalableHorizontalFixedVertical(int xPercent, unsigned widthPercent, unsigned originalScreenWidth, int y, unsigned height)
	{
	int x = originalScreenWidth * xPercent / 100;
	unsigned width = originalScreenWidth * widthPercent / 100;
	return Geometry(SizePolicy::Scalable, SizePolicy::Fixed, x, y, width, height, originalScreenWidth, 0);
	}

Geometry Geometry::scalable(const Point& positionPercent, const Size& sizePercent, const Size& originalScreenSize)
	{
	int x = originalScreenSize.width() * positionPercent.x() / 100;
	int y = originalScreenSize.height() * positionPercent.y() / 100;
	unsigned width = originalScreenSize.width() * sizePercent.width() / 100;
	unsigned height = originalScreenSize.height() * sizePercent.height() / 100;
	return Geometry(SizePolicy::Scalable, SizePolicy::Scalable, x, y, width, height, originalScreenSize.width(), originalScreenSize.height());
	}

Point Geometry::position() const
	{
	return { currX_, currY_ };
	}

Size Geometry::size() const
	{
	return { currW_, currH_ };
	}

void Geometry::resizeAfterScreen(const Size& screenSize)
	{
	if (horizontalPolicy_ == SizePolicy::Scalable)
		{
		currX_ = originalX_ * screenSize.width() / originalScreenW_;
		currW_ = originalW_ * screenSize.width() / originalScreenW_;
		}
	if (verticalPolicy_ == SizePolicy::Scalable)
		{
		currY_ = originalY_ * screenSize.height() / originalScreenH_;
		currH_ = originalH_ * screenSize.height() / originalScreenH_;
		}
	}

Geometry::Geometry(SizePolicy horSizePolicy, SizePolicy vertSizePolicy, int x, int y, unsigned w, unsigned h, unsigned screenW, unsigned screenH):
	horizontalPolicy_(horSizePolicy), verticalPolicy_(vertSizePolicy),
	currX_(x), currY_(y), currW_(w), currH_(h),
	originalX_(x), originalY_(y), originalW_(w), originalH_(h), originalScreenW_(screenW), originalScreenH_(screenH)
	{
	}
