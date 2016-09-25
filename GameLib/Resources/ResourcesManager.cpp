#include "ResourcesManager.h"

#include "GameUtil/ConfigReader.h"
#include "GameUtil/FilePath.h"

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

ResourceID ResourcesManager::getResourceId(const String& fileName)
	{
	auto resource = loadResourceFromFileSystem(fileName);
	ResourceID id = nextId();
	resources.insert(std::make_pair(id, resource));
	return id;
	}

bool ResourcesManager::resourceExist(ResourceID id) const
	{
	return resources.find(id) != resources.end();
	}

const Resource& ResourcesManager::getResource(ResourceID id) const
	{
	return resources.at(id);
	}

ResourceID ResourcesManager::getPackId(const String& fileName)
	{
	auto pack = loadPackFromFileSystem(fileName);
	ResourceID id = nextId();
	resourcePacks.insert(std::make_pair(id, pack));
	return id;
	}

bool ResourcesManager::packExist(ResourceID id) const
	{
	return resourcePacks.find(id) != resourcePacks.end();
	}

const ResourcePack&ResourcesManager::getPack(ResourceID id) const
	{
	return resourcePacks.at(id);
	}

Resource ResourcesManager::loadResourceFromFileSystem(const String& fileName)
	{
	return Resource::loadFromFileSystem(fileName);
	}

ResourcePack ResourcesManager::loadPackFromFileSystem(const String& fileName)
	{
	FilePath packFolderName = FilePath(fileName).folderPath();
	Resource packInfo = loadResourceFromFileSystem(fileName);
	ConfigReader reader(packInfo.asString());

	auto innerPackNames = reader.getArray("InnerPacks");
	std::map<String, ResourcePack> innerPacks;
	for (auto packName : innerPackNames)
		{
		String packRelativeFileName = reader.getString(packName);
		String appRelativeFileName = (packFolderName + packRelativeFileName).string();
		auto pack = loadPackFromFileSystem(appRelativeFileName);
		innerPacks.insert(std::make_pair(packName, pack));
		}

	auto resourceNames = reader.getArray("Resources");
	std::map<String, Resource> resources;
	for (auto resourceName : resourceNames)
		{
		String packRelativeFileName = reader.getString(resourceName);
		String appRelativeFileName = (packFolderName + packRelativeFileName).string();
		auto resource = loadResourceFromFileSystem(appRelativeFileName);
		resources.insert(std::make_pair(resourceName, resource));
		}

	return ResourcePack(resources, innerPacks);
	}

ResourceID ResourcesManager::nextId()
	{
	return ++maxId;
	}
