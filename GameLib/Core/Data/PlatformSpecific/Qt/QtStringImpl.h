#ifndef STRING_IMPL_H
#define STRING_IMPL_H

#include <QString>
#include <iostream>
#include <vector>

class StringImpl
	{
	public:
	StringImpl();
	explicit StringImpl(const char* s);
	StringImpl(const StringImpl& s);

	bool empty() const;
	unsigned length() const;

	StringImpl substr(unsigned start) const;
	StringImpl substr(unsigned start, unsigned len) const;
	StringImpl trim() const;

	std::vector<StringImpl> split(const StringImpl& delimiter) const;
	std::vector<StringImpl> splitNewLine() const;

	int find(const StringImpl& subStr) const;

	int toInt(int defaultValue = 0) const;
	static StringImpl fromInt(int value);

	bool operator<(const StringImpl& s) const;
	bool operator==(const StringImpl& s) const;

	StringImpl& operator+=(const StringImpl& other);

	// Платформенно-зависимые функции, не для использования в клиентском коде
	QString asQString() const;

	private:
	StringImpl(const QString& s);

	private:
	QString string_;
	};

std::ostream& operator<<(std::ostream& out, const StringImpl& s);

#endif // STRING_IMPL_H
