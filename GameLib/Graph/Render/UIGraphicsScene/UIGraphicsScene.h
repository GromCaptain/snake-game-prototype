#ifndef UI_GRAPHICS_SCENE_H
#define UI_GRAPHICS_SCENE_H

#include <map>
#include <memory>
#include <vector>

#include "../IntermediateRenderingStage.h"
#include "UIGraphicsScenePage.h"
#include "Core/Util/Assert.h"
#include "Graph/GraphCore/Texture.h"

namespace Graphics
{

class UIActor;
class UIGraphicsScenePage;

template<typename Page>
class UIGraphicsScene : public IntermediateRenderingStage
	{
	public:
	UIGraphicsScene(const std::vector<Page>& pages, Page startPage): currPage_(startPage)
		{
		for (auto page: pages)
			pages_.emplace(page, UIGraphicsScenePage{});
		}

	virtual Texture modifyFrame(const Texture &frame) const override { return getPage(currPage_).render(frame); }
	virtual void update(std::chrono::milliseconds elapsed) override { getPage(currPage_).update(elapsed); }

	void setCurrentPage(Page page) { currPage_ = page; }
	void addActor(Page targetPage, std::shared_ptr<UIActor> actor) { getPage(targetPage).addActor(actor); }

	private:
	UIGraphicsScenePage& getPage(Page page)
		{
		auto it = pages_.find(page);
		return it -> second;
		}
	const UIGraphicsScenePage& getPage(Page page) const
		{
		auto it = pages_.find(page);
		return it -> second;
		}

	private:
	std::map<Page, UIGraphicsScenePage> pages_;
	Page currPage_;
	};

}

#endif // UI_GRAPHICS_SCENE_H
