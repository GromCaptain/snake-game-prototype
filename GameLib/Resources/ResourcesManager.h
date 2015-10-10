#ifndef RESOURCES_MANAGER_H
#define RESOURCES_MANAGER_H

#include <map>

#include "Resources/ResourceID.h"
#include "Resources/Resource.h"

class String;

class ResourcesManager
	{
	public:
	static ResourcesManager& instance();

	void init();

	ResourceID getId(const String& fileName);
	bool exist(ResourceID id) const;
	const Resource& getResource(ResourceID id) const;

	private:
	ResourcesManager();
	static Resource loadFromFileSystem(const String& fileName);
	ResourceID nextId();

	private:
	std::map<ResourceID, Resource> resources;
	ResourceID maxId;
	};

#endif // RESOURCES_MANAGER_H
