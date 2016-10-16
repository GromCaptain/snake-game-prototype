#include "Color.h"

#include "Core/Util/Assert.h"

namespace Graphics
{

const Color Color::Red = { 255, 0, 0 };
const Color Color::Green = { 0, 255, 0 };
const Color Color::Blue = { 0, 0, 255 };
const Color Color::White = { 255, 255, 255 };
const Color Color::Black = { 0, 0, 0 };
const Color Color::Transparent = { 255, 255, 255, 0 };

Color::Color():
	Color(255, 255, 255)
	{
	}

Color::Color(unsigned red, unsigned green, unsigned blue):
	Color(red, green, blue, 255)
	{
	}

Color::Color(unsigned red, unsigned green, unsigned blue, unsigned alpha):
	red_(red), green_(green), blue_(blue), alpha_(alpha)
	{
	ASSERT(red_ < 256 && green_ < 256 && blue_ < 256 && alpha_ < 256, "wrong color format (some channel is greater than 0xFF)");
	}

unsigned Color::red() const
	{
	return red_;
	}

unsigned Color::green() const
	{
	return green_;
	}

unsigned Color::blue() const
	{
	return blue_;
	}

unsigned Color::alpha() const
	{
	return alpha_;
	}

}
