#ifndef LAYERS_OWNER_H
#define LAYERS_OWNER_H

#include <memory>
#include <vector>

class Rectangle;

namespace Graphics
{

class Actor;

template<typename Layer>
class LayersOwner
	{
	public:
	virtual ~LayersOwner() = default;
	virtual std::vector<Layer> layersOrder() const = 0;
	virtual std::vector<std::shared_ptr<Actor>> actorsInArea(Layer sourceLayer, const Rectangle& area) const = 0;
	};

}

#endif // LAYERS_OWNER_H
