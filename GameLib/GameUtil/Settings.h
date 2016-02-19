#ifndef SETTINGS_H
#define SETTINGS_H

#include "Core/Utility/Geometry/Size.h"

class String;
class ConfigReader;

class Settings
	{
	public:
//	Settings(const String& settingsFileName);

	void loadFromFile(const String& settingsFileName);
	static Settings& globalSettings();

	Size resolution() const;

	private:
	void getSettingsFromReader(const ConfigReader& reader);

	private:
	Size resolution_;
	};

#endif // SETTINGS_H
