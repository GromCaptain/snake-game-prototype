#ifndef UI_COMPONENT_H
#define UI_COMPONENT_H

#include <memory>
#include <vector>

#include "Core/Data/Geometry/Geometry.h"

namespace UI
{

class UIComponent
	{
	public:
	explicit UIComponent(const Geometry& geometry);

	void resizeAfterScreen(const Size& screenSize);

	protected:
	Geometry geometry() const;

	private:
	std::vector<std::shared_ptr<UIComponent>> children_;
	Geometry geometry_;
	};

}

#endif // UI_COMPONENT_H
