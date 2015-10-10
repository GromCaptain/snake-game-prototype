#ifndef STRING_IMPL_H
#define STRING_IMPL_H

#include <QString>
#include <list>

class StringImpl
	{
	public:
	StringImpl();
	explicit StringImpl(const char* s);
	StringImpl(const StringImpl& s);

	bool empty() const;

	StringImpl substr(unsigned start) const;
	StringImpl substr(unsigned start, unsigned len) const;
	StringImpl trim() const;

	std::list<StringImpl> split(const StringImpl& delimiter) const;
	std::list<StringImpl> splitNewLine() const;

	int find(const StringImpl& subStr) const;

	int toInt(int defaultValue = 0) const;

	bool operator<(const StringImpl& s) const;

	// Платформенно-зависимые функции, не для использования в клиентском коде
	QString asQString() const;

	private:
	StringImpl(const QString& s);

	private:
	QString string;
	};

#endif // STRING_IMPL_H
