#include "Resource.h"
#include "PlatformSpecific/Qt/QtResourceImpl.h"

namespace Resources
{

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

const ResourceImpl& Resource::impl() const
	{
	return *pImpl;
	}

Resource Resource::loadFromFileSystem(const String& fileName)
	{
	return Resource(ResourceImpl::loadFromFileSystem(fileName));
	}

}
