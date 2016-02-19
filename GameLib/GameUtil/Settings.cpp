#include "Settings.h"

#include "Resources/ResourcesManager.h"
#include "ConfigReader.h"

void Settings::loadFromFile(const String& settingsFileName)
	{
	auto id = ResourcesManager::instance().getId(settingsFileName);
	auto cfgFile = ResourcesManager::instance().getResource(id);
	ConfigReader cfg(cfgFile.asString());
	getSettingsFromReader(cfg);
	}

Settings& Settings::globalSettings()
	{
	static Settings global;
	return global;
	}

Size Settings::resolution() const
	{
	return resolution_;
	}

void Settings::getSettingsFromReader(const ConfigReader& reader)
	{
	unsigned resolutionWidth = reader.getInt("ResolutionWidth");
	unsigned resolutionHeight = reader.getInt("ResolutionHeight");
	resolution_ = { resolutionWidth, resolutionHeight };
	}
