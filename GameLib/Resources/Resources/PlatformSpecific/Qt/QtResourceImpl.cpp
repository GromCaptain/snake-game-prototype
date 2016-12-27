#include "QtResourceImpl.h"

#include <QFile>

#include "Core/Data/PlatformSpecific/Qt/QtStringImpl.h"

namespace Resources
{

ResourceImpl::ResourceImpl()
	{
	}

ResourceImpl::ResourceImpl(const QByteArray& b):
	bytes_(b)
	{
	}

const Byte* ResourceImpl::data() const
	{
	return bytes_.data();
	}

unsigned ResourceImpl::dataSize() const
	{
	return bytes_.length();
	}

String ResourceImpl::asString() const
	{
	return bytes_.toStdString().c_str();
	}

QByteArray ResourceImpl::byteArray() const
	{
	return bytes_;
	}

ResourceImpl ResourceImpl::loadFromFileSystem(const String& fileName)
	{
	QFile file(fileName.impl().asQString());
	file.open(QIODevice::ReadOnly);
	return ResourceImpl(file.readAll());
	}

}
