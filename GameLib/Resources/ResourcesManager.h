#ifndef RESOURCES_MANAGER_H
#define RESOURCES_MANAGER_H

#include <functional>
#include <map>

#include "Resources/ResourceID.h"
#include "Resources/Resource.h"
#include "Resources/ResourcePack.h"

class String;

namespace Resources
{

class ResourcesManager
	{
	public:
	static ResourcesManager& instance();

	void init();

	ResourceID getResourceId(const String& fileName);
	bool resourceExist(ResourceID id) const;
	const Resource& getResource(ResourceID id) const;

	ResourceID getPackId(const String& fileName);
	ResourceID getPackId(const String &fileName, std::function<void(double)> progressUpdater);
	bool packExist(ResourceID id) const;
	const ResourcePack& getPack(ResourceID id) const;

	private:
	ResourcesManager();
	static Resource loadResourceFromFileSystem(const String& fileName);
	static ResourcePack loadPackFromFileSystem(const String& fileName);

	using ProgressUpdateCallback = std::function<void(double)>;
	static ResourcePack loadPackFromFileSystem(const String& fileName, ProgressUpdateCallback progressUpdater);
	static ResourcePack loadPackFromFileSystem(const String& fileName, double alreadyLoaded, double packLoadShare, ProgressUpdateCallback progressUpdater);

	ResourceID nextId();

	private:
	std::map<ResourceID, Resource> resources_;
	std::map<ResourceID, ResourcePack> resourcePacks_;
	ResourceID maxId_;
	};

}

#endif // RESOURCES_MANAGER_H
