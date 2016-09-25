#ifndef RESOURCE_PACK_H
#define RESOURCE_PACK_H

#include <vector>
#include <map>

class Resource;
class String;

class ResourcePack
	{
	public:
	ResourcePack(const std::map<String, Resource>& resources, const std::map<String, ResourcePack>& innerPacks);
	
	Resource resource(const String& resourceName) const;
	ResourcePack innerPack(const String& packName) const;

	std::vector<String> resourceNames() const;
	std::vector<String> innerPackNames() const;
	
	private:
	std::map<String, Resource> resources_;
	std::map<String, ResourcePack> innerPacks_;
	};

#endif // RESOURCE_PACK_H
