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

unsigned StringImpl::length() const
	{
	return static_cast<unsigned>(string.length());
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

std::vector<StringImpl> StringImpl::split(const StringImpl& delimiter) const
	{
	auto qList = string.split(delimiter.string);
	std::vector<StringImpl> res;
	for (auto s : qList)
		res.push_back(s);
	return res;
	}

std::vector<StringImpl> StringImpl::splitNewLine() const
	{
	auto qList = string.split(QRegExp("[\r\n]"), QString::SkipEmptyParts);
	std::vector<StringImpl> res;
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

StringImpl StringImpl::fromInt(int value)
	{
	return StringImpl(QString::number(value));
	}

bool StringImpl::operator<(const StringImpl& s) const
	{
	return string < s.string;
	}

bool StringImpl::operator==(const StringImpl& s) const
	{
	return string == s.string;
	}

StringImpl&StringImpl::operator+=(const StringImpl& other)
	{
	string += other.string;
	return *this;
	}

QString StringImpl::asQString() const
	{
	return string;
	}



std::ostream& operator<<(std::ostream& out, const StringImpl& s)
	{
	out << s.asQString().toStdString();
	return out;
	}
