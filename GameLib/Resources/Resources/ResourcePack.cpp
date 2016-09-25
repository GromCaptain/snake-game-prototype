#include "ResourcePack.h"

#include "Resource.h"
#include "Core/Assert.h"
#include "Core/String.h"

ResourcePack::ResourcePack(const std::map<String, Resource>& resources, const std::map<String, ResourcePack>& innerPacks):
	resources_(resources), innerPacks_(innerPacks)
	{
	}

Resource ResourcePack::resource(const String& resourceName) const
	{
	auto it = resources_.find(resourceName);
	ASSERT(it != resources_.end(), "invalid resource name");
	return it -> second;
	}

ResourcePack ResourcePack::innerPack(const String& packName) const
	{
	auto it = innerPacks_.find(packName);
	ASSERT(it != innerPacks_.end(), "invalid resource pack name");
	return it -> second;
	}

std::vector<String> ResourcePack::resourceNames() const
	{
	std::vector<String> result;
	result.reserve(resources_.size());
	for (auto pair : resources_)
		result.push_back(pair.first);
	return result;
	}

std::vector<String> ResourcePack::innerPackNames() const
	{
	std::vector<String> result;
	result.reserve(innerPacks_.size());
	for (auto pair : innerPacks_)
		result.push_back(pair.first);
	return result;
	}

