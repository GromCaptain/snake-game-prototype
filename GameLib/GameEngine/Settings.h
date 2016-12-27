#ifndef SETTINGS_H
#define SETTINGS_H

#include "Core/Data/Geometry/Size.h"

class String;
class ConfigReader;

namespace GameEngine
{

class Settings
	{
	public:
	void loadFromFile(const String& settingsFileName);
	static Settings& globalSettings();

	Size resolution() const;

	private:
	void getSettingsFromReader(const ConfigReader& reader);

	private:
	Size resolution_;
	};

}

#endif // SETTINGS_H
