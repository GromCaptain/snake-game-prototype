#ifndef SIZE_H
#define SIZE_H

class Size
	{
	public:
	Size() = default;
	Size(unsigned width, unsigned height);

	unsigned width() const;
	unsigned height() const;

	bool operator==(const Size& other) const;

	private:
	unsigned width_, height_;
	};

#endif // SIZE_H
