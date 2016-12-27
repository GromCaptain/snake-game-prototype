#include "ResourcesManager.h"

#include "Core/Util/ConfigReader.h"
#include "Resources/FilePath.h"

namespace Resources
{

ResourcesManager::ResourcesManager():
	maxId_(0)
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
	resources_.insert(std::make_pair(id, resource));
	return id;
	}

bool ResourcesManager::resourceExist(ResourceID id) const
	{
	return resources_.find(id) != resources_.end();
	}

const Resource& ResourcesManager::getResource(ResourceID id) const
	{
	return resources_.at(id);
	}

ResourceID ResourcesManager::getPackId(const String& fileName)
	{
	auto pack = loadPackFromFileSystem(fileName);
	ResourceID id = nextId();
	resourcePacks_.insert(std::make_pair(id, pack));
	return id;
	}

bool ResourcesManager::packExist(ResourceID id) const
	{
	return resourcePacks_.find(id) != resourcePacks_.end();
	}

const ResourcePack&ResourcesManager::getPack(ResourceID id) const
	{
	return resourcePacks_.at(id);
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
	return ++maxId_;
	}

}
