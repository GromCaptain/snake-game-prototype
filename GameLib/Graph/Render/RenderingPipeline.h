#ifndef RENDERING_PIPELINE_H
#define RENDERING_PIPELINE_H

#include <chrono>
#include <memory>
#include <vector>

namespace Graphics
{

class Texture;
class InitialRenderingStage;
class IntermediateRenderingStage;

class RenderingPipeline
	{
	public:
	RenderingPipeline(std::shared_ptr<InitialRenderingStage> initialStage, const std::vector<std::shared_ptr<IntermediateRenderingStage>>& intermediateStages);

	Texture renderFrame() const;
	void update(std::chrono::milliseconds elapsed);

	private:
	const std::shared_ptr<InitialRenderingStage> initialStage_;
	const std::vector<std::shared_ptr<IntermediateRenderingStage>> intermediateStages_;
	};

}

#endif // RENDERINGPIPELINE_H
