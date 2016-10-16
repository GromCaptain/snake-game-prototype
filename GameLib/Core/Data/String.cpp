#include "String.h"
#include "PlatformSpecific/Qt/QtStringImpl.h"

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

unsigned String::length() const
	{
	return pImpl -> length();
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

std::vector<String> String::split(const String& delimiter) const
	{
	auto implList = pImpl -> split(delimiter.impl());
	std::vector<String> res;
	for (auto impl : implList)
		res.push_back(impl);
	return res;
	}

std::vector<String> String::splitNewLine() const
	{
	auto implList = pImpl -> splitNewLine();
	std::vector<String> res;
	for (auto impl : implList)
		res.push_back(impl);
	return res;
	}

String String::join(const std::vector<String>& strings, const String& separator)
	{
	if (strings.empty())
		return emptyString;

	if (strings.size() == 1)
		return strings.at(0);

	String result = strings.at(0);
	auto sz = strings.size();
	for (size_t i = 1; i < sz; ++i)
		{
		result += separator;
		result += strings.at(i);
		}
	return result;
	}

int String::find(const String& subStr) const
	{
	return pImpl -> find(subStr.impl());
	}

int String::toInt(int defaultValue) const
	{
	return pImpl -> toInt(defaultValue);
	}

String String::fromInt(int value)
	{
	return StringImpl::fromInt(value);
	}

bool String::operator<(const String& s) const
	{
	return impl() < s.impl();
	}

bool String::operator==(const String& s) const
	{
	return impl() == s.impl();
	}

String& String::operator+=(const String& other)
	{
	*(pImpl) += *(other.pImpl);
	return *this;
	}

StringImpl& String::impl() const
	{
	return *pImpl;
	}

bool operator!=(const String& s1, const String& s2)
	{
	return ! (s1 == s2);
	}


String operator+(const String& s1, const String& s2)
	{
	String result(s1);
	result += s2;
	return result;
	}

std::ostream& operator<<(std::ostream& out, const String& s)
	{
	out << s.impl();
	return out;
	}
