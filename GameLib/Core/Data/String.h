#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <memory>
#include <vector>

class StringImpl;

class String
	{
	public:
	String();
	String(const char* s);
	String(const String& s);
	String(StringImpl impl);

	bool empty() const;
	unsigned length() const;

	String substr(unsigned start) const;
	String substr(unsigned start, unsigned len) const;
	String trim() const;

	std::vector<String> split(const String& delimiter) const;
	std::vector<String> splitNewLine() const;

	static String join(const std::vector<String>& strings, const String& separator);

	int find(const String& subStr) const;

	int toInt(int defaultValue = 0) const;
	static String fromInt(int value);

	bool operator<(const String& s) const;
	bool operator==(const String& s) const;

	String& operator+=(const String& other);

	static const String emptyString;

	StringImpl& impl() const;

	private:
	std::shared_ptr<StringImpl> pImpl;
	};

bool operator!=(const String& s1, const String& s2);
String operator+(const String& s1, const String& s2);

std::ostream& operator<<(std::ostream& out, const String& s);

#endif // STRING_H
