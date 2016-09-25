#include "ConfigReader.h"

#include <algorithm>
#include <utility>

ConfigReader::ConfigReader(const String& configurationText):
	properties(parseConfig(configurationText))
	{
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

std::vector<String> ConfigReader::getArray(const String& propName) const
	{
	if (!propertyExist(propName))
		return {};
	
	auto prop = property(propName);
	if (prop.trim().empty())
		return {};
	if (prop.substr(0, 1) != "[" || prop.substr(prop.length() - 1) != "]")
		return { prop };

	auto notTrimmedElems = prop.substr(1, prop.length() - 2).split(",");
	std::vector<String> result(notTrimmedElems.size());
	std::transform(notTrimmedElems.begin(), notTrimmedElems.end(), result.begin(), [](const String& s) { return s.trim(); });
	return result;
	}

bool ConfigReader::propertyExist(const String& propName) const
	{
	return properties.find(propName) != properties.end();
	}

std::map<String, String> ConfigReader::parseConfig(const String& str)
	{
	std::map<String, String> resultProperties;
	auto lines = str.splitNewLine();
	for (auto line : lines)
		{
		auto propPair = parseLine(line);
		if (!propPair.first.empty())
			resultProperties.insert(propPair);
		}
	return resultProperties;
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

