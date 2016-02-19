#include "ConfigReader.h"

#include <utility>

ConfigReader::ConfigReader(const String& configurationText)
	{
	parse(configurationText);
	}

String ConfigReader::getString(const String& propName) const
	{
	if (!propertyExist(propName))
		return String::emptyString;
	return property(propName);
	}

int ConfigReader::getInt(const String& propName) const
	{
	if (!propertyExist(propName))
		return 0;
	return property(propName).toInt();
	}

bool ConfigReader::propertyExist(const String& propName) const
	{
	return properties.find(propName) != properties.end();
	}

void ConfigReader::parse(const String& str)
	{
	auto lines = str.splitNewLine();
	for (auto line : lines)
		{
		auto propPair = parseLine(line);
		if (!propPair.first.empty())
			properties.insert(propPair);
		}
	}

std::pair<String, String> ConfigReader::parseLine(const String& line)
	{
	int delimPos = line.find("=");
	if (delimPos < 0)
		return std::make_pair(String::emptyString, String::emptyString);
	String propKey = line.substr(0, delimPos).trim(), propValue = line.substr(delimPos + 1).trim();
	return std::make_pair(propKey, propValue);
	}

String ConfigReader::property(const String& propName) const
	{
	return properties.at(propName);
	}

