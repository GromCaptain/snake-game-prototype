#ifndef INTERMEDIATE_RENDERING_STAGE_H
#define INTERMEDIATE_RENDERING_STAGE_H

#include <chrono>

namespace Graphics
{

class Texture;

class IntermediateRenderingStage
	{
	public:
	virtual ~IntermediateRenderingStage();
	virtual Texture modifyFrame(const Texture& frame) const = 0;
	virtual void update(std::chrono::milliseconds elapsed) = 0;
	};

}

#endif // INTERMEDIATE_RENDERING_STAGE_H
