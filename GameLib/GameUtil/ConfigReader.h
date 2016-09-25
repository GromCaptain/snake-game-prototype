#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include <vector>
#include <map>

#include "Resources/Resources/Byte.h"
#include "Core/String.h"

class ConfigReader
	{
	public:
	explicit ConfigReader(const String& configurationText);

	String getString(const String& propName) const;
	int getInt(const String& propName) const;
	std::vector<String> getArray(const String& propName) const;

	bool propertyExist(const String& propName) const;

	private:
	static std::map<String, String> parseConfig(const String& str);
	static std::pair<String, String> parseLine(const String& line);
	String property(const String& propName) const;

	private:
	std::map<String, String> properties;
	};

#endif // CONFIG_READER_H
