#ifndef INITIAL_RENDERING_STAGE_H
#define INITIAL_RENDERING_STAGE_H

#include <chrono>

namespace Graphics
{

class Texture;

class InitialRenderingStage
	{
	public:
	InitialRenderingStage();
	virtual Texture renderFrame() const = 0;
	virtual void update(std::chrono::milliseconds elapsed) = 0;
	};

}

#endif // INITIAL_RENDERING_STAGE_H
