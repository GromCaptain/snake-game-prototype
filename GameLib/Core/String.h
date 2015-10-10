#ifndef STRING_H
#define STRING_H

#include <memory>
#include <list>

class StringImpl;

class String
	{
	public:
	String();
	String(const char* s);
	String(const String& s);
	String(StringImpl impl);

	bool empty() const;

	String substr(unsigned start) const;
	String substr(unsigned start, unsigned len) const;
	String trim() const;

	std::list<String> split(const String& delimiter) const;
	std::list<String> splitNewLine() const;

	int find(const String& subStr) const;

	int toInt(int defaultValue = 0) const;

	bool operator<(const String& s) const;
	bool operator==(const String& s) const;

	static const String emptyString;

	StringImpl& impl() const;

	private:
	std::shared_ptr<StringImpl> pImpl;
	};

bool operator!=(const String& s1, const String& s2);

#endif // STRING_H
