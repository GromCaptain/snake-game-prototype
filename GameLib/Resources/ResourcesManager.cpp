#include "ResourcesManager.h"

ResourcesManager::ResourcesManager():
	maxId(0)
	{
	}

ResourcesManager& ResourcesManager::instance()
	{
	static ResourcesManager mgr;
	return mgr;
	}

void ResourcesManager::init()
	{
	//
	}

ResourceID ResourcesManager::getId(const String& fileName)
	{
	auto resource = loadFromFileSystem(fileName);
	ResourceID id = nextId();
	resources.insert(std::make_pair(id, resource));
	return id;
	}

bool ResourcesManager::exist(ResourceID id) const
	{
	return resources.find(id) != resources.end();
	}

const Resource& ResourcesManager::getResource(ResourceID id) const
	{
	return resources.at(id);
	}

Resource ResourcesManager::loadFromFileSystem(const String& fileName)
	{
	return Resource::loadFromFileSystem(fileName);
	}

ResourceID ResourcesManager::nextId()
	{
	return ++maxId;
	}
