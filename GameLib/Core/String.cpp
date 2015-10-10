#include "String.h"
#include "PlaftormSpecific/QtStringImpl.h"

const String String::emptyString = String();

String::String():
	pImpl(new StringImpl())
	{
	}

String::String(const char* s):
	pImpl(new StringImpl(s))
	{
	}

String::String(const String& s):
	pImpl(new StringImpl(s.impl()))
	{
	}

String::String(StringImpl impl):
	pImpl(new StringImpl(impl))
	{
	}

bool String::empty() const
	{
	return pImpl -> empty();
	}

String String::substr(unsigned start) const
	{
	return pImpl -> substr(start);
	}

String String::substr(unsigned start, unsigned len) const
	{
	return pImpl -> substr(start, len);
	}

String String::trim() const
	{
	return pImpl -> trim();
	}

std::list<String> String::split(const String& delimiter) const
	{
	auto implList = pImpl -> split(delimiter.impl());
	std::list<String> res;
	for (auto impl : implList)
		res.push_back(impl);
	return res;
	}

std::list<String> String::splitNewLine() const
	{
	auto implList = pImpl -> splitNewLine();
	std::list<String> res;
	for (auto impl : implList)
		res.push_back(impl);
	return res;
	}

int String::find(const String& subStr) const
	{
	return pImpl -> find(subStr.impl());
	}

int String::toInt(int defaultValue) const
	{
	return pImpl -> toInt(defaultValue);
	}

bool String::operator<(const String& s) const
	{
	return impl() < s.impl();
	}

StringImpl String::impl() const
	{
	return *pImpl;
	}

