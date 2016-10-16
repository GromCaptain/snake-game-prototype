#ifndef FILE_PATH_H
#define FILE_PATH_H

#include <vector>

#include "Core/Data/String.h"

namespace Resources
{

class FilePath
	{
	public:
	FilePath(const String& path);
	FilePath(const FilePath& other);

	String string() const;

	FilePath folderPath() const;

	FilePath& operator+=(const String& relPath);
	FilePath& operator+=(const FilePath& relPath);

	private:
	FilePath(const std::vector<String>& pathParts);

	static String withoutLeadingAndTrailingSeparators(const String& path);
	static std::vector<String> splitPathToParts(const String& path);
	static unsigned simplifiedSize(const std::vector<String>& parts);
	static std::vector<String> simplifyUpsInParts(const std::vector<String>& parts);
	static std::vector<String> pathToParts(const String& path);
	static String joinParts(const std::vector<String>& parts, const String& separator);

	private:
	std::vector<String> pathParts_;
	static const String mainSeparator;
	static const String additionalSeparator;
	};

FilePath operator+(const FilePath& path1, const FilePath& path2);

}

#endif // FILE_PATH_H
