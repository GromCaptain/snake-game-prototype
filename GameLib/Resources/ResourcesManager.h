#ifndef RESOURCES_MANAGER_H
#define RESOURCES_MANAGER_H

#include <map>

#include "Resources/ResourceID.h"
#include "Resources/Resource.h"
#include "Resources/ResourcePack.h"

class String;

class ResourcesManager
	{
	public:
	static ResourcesManager& instance();

	void init();

	ResourceID getResourceId(const String& fileName);
	bool resourceExist(ResourceID id) const;
	const Resource& getResource(ResourceID id) const;

	ResourceID getPackId(const String& fileName);
	bool packExist(ResourceID id) const;
	const ResourcePack& getPack(ResourceID id) const;

	private:
	ResourcesManager();
	static Resource loadResourceFromFileSystem(const String& fileName);
	static ResourcePack loadPackFromFileSystem(const String& fileName);
	ResourceID nextId();

	private:
	std::map<ResourceID, Resource> resources;
	std::map<ResourceID, ResourcePack> resourcePacks;
	ResourceID maxId;
	};

#endif // RESOURCES_MANAGER_H
