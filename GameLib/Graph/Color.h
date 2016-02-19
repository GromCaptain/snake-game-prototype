#ifndef COLOR_H
#define COLOR_H

namespace Graphics
{

class Color
	{
	public:
	Color();
	Color(unsigned red, unsigned green, unsigned blue);
	Color(unsigned red, unsigned green, unsigned blue, unsigned alpha);

	unsigned red() const;
	unsigned green() const;
	unsigned blue() const;
	unsigned alpha() const;

	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color White;
	static const Color Black;
	static const Color Transparent;

	private:
	unsigned red_, green_, blue_;
	unsigned alpha_ = 255;
	};

}

#endif // COLOR_H
