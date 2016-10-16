#include "FilePath.h"

#include <algorithm>

namespace Resources
{

const String FilePath::mainSeparator = "/";
const String FilePath::additionalSeparator = "\\";

const String upString = String("..");

FilePath::FilePath(const String& path):
	pathParts_(pathToParts(path))
	{
	}

FilePath::FilePath(const FilePath& other):
	pathParts_(other.pathParts_)
	{
	}

String FilePath::string() const
	{
	return joinParts(pathParts_, mainSeparator);
	}

FilePath FilePath::folderPath() const
	{
	if (pathParts_.empty())
		return FilePath("..");
	if (pathParts_.size() == 1)
		return FilePath("");
	if (pathParts_.back() == upString)
		{
		std::vector<String> partsWithOnlyUps(pathParts_.size() + 1);
		std::fill_n(partsWithOnlyUps.begin(), pathParts_.size() + 1, upString);
		return FilePath(partsWithOnlyUps);
		}
	std::vector<String> partsExceptLast(pathParts_.size() - 1);
	partsExceptLast.reserve(pathParts_.size() - 1);
	std::copy(pathParts_.begin(), std::prev(pathParts_.end()), partsExceptLast.begin());
	return FilePath(partsExceptLast);
	}

FilePath& FilePath::operator+=(const String& relPath)
	{
	(*this) += FilePath(relPath);
	return *this;
	}

FilePath& FilePath::operator+=(const FilePath& relPath)
	{
	pathParts_.insert(pathParts_.end(), relPath.pathParts_.begin(), relPath.pathParts_.end());
	pathParts_ = simplifyUpsInParts(pathParts_);
	return *this;
	}

FilePath::FilePath(const std::vector<String>& pathParts):
	pathParts_(pathParts)
	{
	}

String FilePath::withoutLeadingAndTrailingSeparators(const String& path)
	{
	if (path.empty())
		return String::emptyString;
	String leadingChar = path.substr(0, 1);
	String trailingChar = path.substr(path.length() - 1, 1);
	unsigned firstCharPos = (leadingChar == mainSeparator || leadingChar == additionalSeparator) ? 1 : 0;
	unsigned lastCharPos = (trailingChar == mainSeparator || trailingChar == additionalSeparator) ? path.length() - 2 : path.length() - 1;
	if (firstCharPos > lastCharPos)
		return String::emptyString;
	return path.substr(firstCharPos, lastCharPos - firstCharPos + 1);
	}

std::vector<String> FilePath::splitPathToParts(const String& path)
	{
	if (path.empty())
		return {};
	std::vector<String> result;
	auto splittedByMain = withoutLeadingAndTrailingSeparators(path).split(mainSeparator);
	for (auto part : splittedByMain)
		{
		auto splittedByAdditional = part.split(additionalSeparator);
		for (auto subPart : splittedByAdditional)
			result.push_back(subPart);
		}
	return result;
	}

unsigned FilePath::simplifiedSize(const std::vector<String>& parts)
	{
	unsigned result = 0;
	unsigned notUpsCount = 0;
	for (const auto& part : parts)
		{
		if (part != upString)
			{
			++notUpsCount;
			continue;
			}
		if (notUpsCount == 0)
			++result;
		else
			--notUpsCount;
		}
	return result + notUpsCount;
	}

std::vector<String> FilePath::simplifyUpsInParts(const std::vector<String>& parts)
	{
	if (parts.empty())
		return {};
	std::vector<String> result(simplifiedSize(parts));
	auto lastUpIt = std::find(parts.rbegin(), parts.rend(), upString);
	auto destIt = std::copy(parts.rbegin(), lastUpIt, result.rbegin());
	unsigned upsCount = 0;
	for (auto it = lastUpIt; it != parts.rend(); ++it)
		{
		if (*it == upString)
			++upsCount;
		else
			{
			if (upsCount == 0)
				*(destIt++) = *it;
			else
				--upsCount;
			}
		}
	std::fill_n(destIt, upsCount, upString);
	return result;
	}

std::vector<String> FilePath::pathToParts(const String& path)
	{
	auto parts = splitPathToParts(path);
	return simplifyUpsInParts(parts);
	}

String FilePath::joinParts(const std::vector<String>& parts, const String& separator)
	{
	return String::join(parts, separator);
	}

FilePath operator+(const FilePath& path1, const FilePath& path2)
	{
	FilePath result(path1);
	result += path2;
	return result;
	}

}
