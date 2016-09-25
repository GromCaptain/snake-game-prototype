#include "Animation.h"

#include "Core/Utility/Geometry/Rectangle.h"

#include <QDebug>

namespace Graphics
{

Animation::Animation(const Graphics::Texture& frame):
	atlas_(frame), framesCount_(0),
	frameRects_({ frame.rect() }), running_(false),
	size_(frame.rect().size()), frameDuration_(0)
	{
	}

Animation::Animation(const Texture& atlas, const std::vector<Rectangle>& frameRects, std::chrono::milliseconds frameDuration):
	atlas_(atlas), framesCount_(frameRects.size()),
	frameRects_(frameRects), running_(framesCount_ > 1),
	size_(frameRects_.front().size()), frameDuration_(frameDuration)
	{
	}

Texture Animation::currentFrame() const
	{
	auto rect = frameRects_[currFrame_];
	return atlas_.crop(rect);
	}

Size Animation::size() const
	{
	return size_;
	}

void Animation::update(std::chrono::milliseconds elapsed)
	{
	if (!running_)
		return;
	elapsedAfterLastFrame_ += elapsed;
	if (elapsedAfterLastFrame_ >= frameDuration_)
		{
		unsigned framesElapsed = elapsedAfterLastFrame_ / frameDuration_;
		elapsedAfterLastFrame_ -= framesElapsed * frameDuration_;
		currFrame_ += framesElapsed;
		currFrame_ %= framesCount_;
		}
	}

void Animation::reset()
	{
	currFrame_ = 0;
	elapsedAfterLastFrame_ = std::chrono::milliseconds(0);
	}

void Animation::pause()
	{
	running_ = false;
	}

void Animation::resume()
	{
	if (framesCount_ > 1)
		running_ = true;
	}

bool Animation::running() const
	{
	return running_;
	}

}
