#include "QtStringImpl.h"

#include <QStringList>
#include <QRegExp>

StringImpl::StringImpl()
	{
	}

StringImpl::StringImpl(const char* s):
	string(s)
	{
	}

StringImpl::StringImpl(const StringImpl& s):
	string(s.string)
	{
	}

StringImpl::StringImpl(const QString& s):
	string(s)
	{
	}

bool StringImpl::empty() const
	{
	return string.isEmpty();
	}

StringImpl StringImpl::substr(unsigned start) const
	{
	return string.mid(start);
	}

StringImpl StringImpl::substr(unsigned start, unsigned len) const
	{
	return string.mid(start, len);
	}

StringImpl StringImpl::trim() const
	{
	return string.trimmed();
	}

std::list<StringImpl> StringImpl::split(const StringImpl& delimiter) const
	{
	auto qList = string.split(delimiter.string);
	std::list<StringImpl> res;
	for (auto s : qList)
		res.push_back(s);
	return res;
	}

std::list<StringImpl> StringImpl::splitNewLine() const
	{
	auto qList = string.split(QRegExp("[\r\n]"), QString::SkipEmptyParts);
	std::list<StringImpl> res;
	for (auto s : qList)
		res.push_back(s);
	return res;
	}

int StringImpl::find(const StringImpl& subStr) const
	{
	return string.indexOf(subStr.string);
	}

int StringImpl::toInt(int defaultValue) const
	{
	bool ok = true;
	int res = string.toInt(&ok);
	return ok ? res : defaultValue;
	}

bool StringImpl::operator<(const StringImpl& s) const
	{
	return string < s.string;
	}

bool StringImpl::operator==(const StringImpl& s) const
	{
	return string == s.string;
	}

QString StringImpl::asQString() const
	{
	return string;
	}

