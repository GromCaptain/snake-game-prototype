#include "Resource.h"
#include "PlatformSpecific/QtResourceImpl.h"

Resource::Resource():
	pImpl(new ResourceImpl)
	{
	}

Resource::Resource(const ResourceImpl& impl):
	pImpl(new ResourceImpl(impl))
	{
	}

const Byte* Resource::data() const
	{
	return pImpl -> data();
	}

unsigned Resource::dataSize() const
	{
	return pImpl -> dataSize();
	}

String Resource::asString() const
	{
	return pImpl -> asString();
	}

Resource Resource::loadFromFileSystem(const String& fileName)
	{
	return ResourceImpl::loadFromFileSystem(fileName);
	}

