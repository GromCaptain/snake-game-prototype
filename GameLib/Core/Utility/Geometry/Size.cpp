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
