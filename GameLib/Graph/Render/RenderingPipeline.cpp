#include "RenderingPipeline.h"

#include "InitialRenderingStage.h"
#include "IntermediateRenderingStage.h"
#include "Graph/GraphCore/Texture.h"

namespace Graphics
{

RenderingPipeline::RenderingPipeline(std::shared_ptr<InitialRenderingStage> initialStage, const std::vector<std::shared_ptr<IntermediateRenderingStage> >& intermediateStages):
	initialStage_(initialStage), intermediateStages_(intermediateStages)
	{
	}

Texture RenderingPipeline::renderFrame() const
	{
	Texture frame = initialStage_ -> renderFrame();
	for (auto stagePtr : intermediateStages_)
		frame = stagePtr -> modifyFrame(frame);
	return frame;
	}

void RenderingPipeline::update(std::chrono::milliseconds elapsed)
	{
	initialStage_ -> update(elapsed);
	for (auto stagePtr : intermediateStages_)
		stagePtr -> update(elapsed);
	}

}
