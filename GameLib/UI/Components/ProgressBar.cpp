#include "ProgressBar.h"

#include "Core/Utility/Geometry/Rectangle.h"
#include "Graph/AnimationCollection.h"
#include "Graph/Animation.h"

namespace UI
{

const unsigned progressLineHorBorder = 5;

ProgressBar::ProgressBar(const Geometry& geometry, ProgressUpdater progressUpdater):
	UIComponent(geometry),
	progressUpdater_(progressUpdater)
	{
	}

Graphics::Texture ProgressBar::updateActorFrame(Graphics::AnimationCollection& animations, std::chrono::milliseconds elapsed)
	{
	unsigned percent = progressUpdater_();
	unsigned progressLineWidth = geometry().size().width() - 2 * progressLineHorBorder;
	auto backgroundTexture = buildBackgroundTexture(animations);
	auto progressLineTexture = buildProgressLineTexture(animations, elapsed, progressLineWidth, percent);
	Rectangle outerRect = backgroundTexture.rect(), innerRect = progressLineTexture.rect();
	Point progressLinePos = { (outerRect.width() - innerRect.width()) / 2, (outerRect.height() - innerRect.height()) / 2 };
	backgroundTexture.drawTexture(progressLineTexture, Rectangle(progressLinePos, innerRect.size()));
	return backgroundTexture;
	}

Graphics::Texture ProgressBar::buildBackgroundTexture(const Graphics::AnimationCollection& animations) const
	{
	auto leftEndTexture = animations.animation("bkgLeftEnd").currentFrame();
	auto rightEndTexture = animations.animation("bkgRightEnd").currentFrame();
	auto middleTexture = animations.animation("bkgMiddle").currentFrame();

	unsigned middleTextureWidth = middleTexture.rect().width();
	unsigned middleTextureHeight = middleTexture.rect().height();
	unsigned middleWidth = geometry().size().width() - leftEndTexture.rect().width() - rightEndTexture.rect().width();
	Graphics::Texture bkgTexture(geometry().size(), Graphics::Color(0, 0, 0, 0));
	Rectangle leftRect = leftEndTexture.rect();

	bkgTexture.drawTexture(leftEndTexture, leftRect);

	unsigned middleRepeats = middleWidth / middleTextureWidth;
	for (unsigned i = 0; i < middleRepeats; ++i)
		{
		int left = leftRect.width() + i * middleTextureWidth;
		Rectangle rect(left, 0, middleTextureWidth, middleTextureHeight);
		bkgTexture.drawTexture(middleTexture, rect);
		}
	auto lastMiddleTexture = middleTexture.crop(Rectangle(0, 0, middleWidth - middleTextureWidth * middleRepeats, middleTextureHeight));
	Rectangle lastMiddleRect(Point(leftRect.width() + middleRepeats * middleTextureWidth, 0), lastMiddleTexture.rect().size());
	bkgTexture.drawTexture(lastMiddleTexture, lastMiddleRect);

	Rectangle rightRect(Point(leftRect.width() + middleWidth, 0), rightEndTexture.rect().size());
	bkgTexture.drawTexture(rightEndTexture, rightRect);

	return bkgTexture;
	}

Graphics::Texture ProgressBar::buildProgressLineTexture(Graphics::AnimationCollection& animations, std::chrono::milliseconds elapsed, unsigned width, unsigned percent) const
	{
	auto& linePartAnimation = animations.animation("line");
	linePartAnimation.update(elapsed);
	auto linePartTexture = linePartAnimation.currentFrame();
	unsigned partWidth = linePartTexture.rect().width(), partHeight = linePartTexture.rect().height();
	Graphics::Texture lineTexture(Size(width, partHeight), Graphics::Color(0, 0, 0, 0));
	unsigned filledLineWidth = width * percent / 100;
	unsigned partRepeat = filledLineWidth / partWidth;
	for (unsigned i = 0; i < partRepeat; ++i)
		{
		Rectangle rect(i * partWidth, 0, partWidth, partHeight);
		lineTexture.drawTexture(linePartTexture, rect);
		}
	auto lastPartTexture = linePartTexture.crop(Rectangle(0, 0, filledLineWidth - partWidth * partRepeat, partHeight));
	Rectangle lastPartRect(Point(partRepeat * partWidth, 0), lastPartTexture.rect().size());
	lineTexture.drawTexture(lastPartTexture, lastPartRect);
	return lineTexture;
	}

}
