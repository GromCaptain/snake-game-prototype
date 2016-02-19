#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <chrono>

#include "Texture.h"
#include "Core/Utility/Geometry/Size.h"

class Rectangle;

namespace Graphics
{

class Animation
	{
	public:
	explicit Animation(const Texture& frame);
	Animation(const Texture& atlas, const std::vector<Rectangle>& frameRects_, std::chrono::milliseconds frameDuration);

	Texture currentFrame() const;

	Size size() const;

	void update(std::chrono::milliseconds elapsed);
	void reset();

	void pause();
	void resume();

	bool running() const;

	private:
	Texture atlas_;
	unsigned currFrame_ = 0;
	unsigned framesCount_;
	std::vector<Rectangle> frameRects_;
	bool running_;
	Size size_;
	std::chrono::milliseconds frameDuration_;
	std::chrono::milliseconds elapsedAfterLastFrame_ = std::chrono::milliseconds(0);
	};

}

#endif // ANIMATION_H
