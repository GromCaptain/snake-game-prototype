#include "QtStringImpl.h"

#include <QStringList>
#include <QRegExp>

StringImpl::StringImpl()
	{
	}

StringImpl::StringImpl(const char* s):
	string_(s)
	{
	}

StringImpl::StringImpl(const StringImpl& s):
	string_(s.string_)
	{
	}

StringImpl::StringImpl(const QString& s):
	string_(s)
	{
	}

bool StringImpl::empty() const
	{
	return string_.isEmpty();
	}

unsigned StringImpl::length() const
	{
	return static_cast<unsigned>(string_.length());
	}

StringImpl StringImpl::substr(unsigned start) const
	{
	return string_.mid(start);
	}

StringImpl StringImpl::substr(unsigned start, unsigned len) const
	{
	return string_.mid(start, len);
	}

StringImpl StringImpl::trim() const
	{
	return string_.trimmed();
	}

std::vector<StringImpl> StringImpl::split(const StringImpl& delimiter) const
	{
	auto qList = string_.split(delimiter.string_);
	std::vector<StringImpl> res;
	for (auto s : qList)
		res.push_back(s);
	return res;
	}

std::vector<StringImpl> StringImpl::splitNewLine() const
	{
	auto qList = string_.split(QRegExp("[\r\n]"), QString::SkipEmptyParts);
	std::vector<StringImpl> res;
	for (auto s : qList)
		res.push_back(s);
	return res;
	}

int StringImpl::find(const StringImpl& subStr) const
	{
	return string_.indexOf(subStr.string_);
	}

int StringImpl::toInt(int defaultValue) const
	{
	bool ok = true;
	int res = string_.toInt(&ok);
	return ok ? res : defaultValue;
	}

StringImpl StringImpl::fromInt(int value)
	{
	return StringImpl(QString::number(value));
	}

bool StringImpl::operator<(const StringImpl& s) const
	{
	return string_ < s.string_;
	}

bool StringImpl::operator==(const StringImpl& s) const
	{
	return string_ == s.string_;
	}

StringImpl&StringImpl::operator+=(const StringImpl& other)
	{
	string_ += other.string_;
	return *this;
	}

QString StringImpl::asQString() const
	{
	return string_;
	}



std::ostream& operator<<(std::ostream& out, const StringImpl& s)
	{
	out << s.asQString().toStdString();
	return out;
	}
