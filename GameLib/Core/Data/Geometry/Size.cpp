#include "Size.h"

Size::Size(unsigned width, unsigned height):
	width_(width), height_(height)
	{
	}

unsigned Size::width() const
	{
	return width_;
	}

unsigned Size::height() const
	{
	return height_;
	}

bool Size::operator==(const Size& other) const
	{
	return width_ == other.width_ && height_ == other.height_;
	}
