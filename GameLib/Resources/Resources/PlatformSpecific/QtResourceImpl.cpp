#include "QtResourceImpl.h"

#include <QFile>

#include "Core/PlaftormSpecific/QtStringImpl.h"

ResourceImpl::ResourceImpl()
	{
	}

ResourceImpl::ResourceImpl(const QByteArray& b):
	bytes(b)
	{
	}

const Byte* ResourceImpl::data() const
	{
	return bytes.data();
	}

unsigned ResourceImpl::dataSize() const
	{
	return bytes.length();
	}

String ResourceImpl::asString() const
	{
	return bytes.toStdString().c_str();
	}

QByteArray ResourceImpl::byteArray() const
	{
	return bytes;
	}

ResourceImpl ResourceImpl::loadFromFileSystem(const String& fileName)
	{
	QFile file(fileName.impl().asQString());
	file.open(QIODevice::ReadOnly);
	return ResourceImpl(file.readAll());
	}

