#include <gtest/gtest.h>
#include "Core/Util/ConfigReader.h"

TEST(Config, PropertyExistOnEmpty)
	{
	ConfigReader cr(String::emptyString);
	bool exist = cr.propertyExist("something");
	EXPECT_FALSE(exist);
	}

TEST(Config, PropertyExistOnSingleEntry)
	{
	ConfigReader cr(String("hello=world"));
	bool exist = cr.propertyExist("hello");
	EXPECT_TRUE(exist);
	}

TEST(Config, PropertyExistOnSingleEntrySpaces)
	{
	ConfigReader cr(String(" hello\t=\t world \t"));
	bool exist = cr.propertyExist("hello");
	EXPECT_TRUE(exist);
	}

TEST(Config, PropertyExistOnAnotherEntry)
	{
	ConfigReader cr(String("hello=world"));
	bool exist = cr.propertyExist("world");
	EXPECT_FALSE(exist);
	}

TEST(Config, PropertyExistOnThreeEntries)
	{
	ConfigReader cr(String("Name=Sherlock Holmes\nAddress = Baker Street, 221 b\nAnswer =42"));
	bool exist = cr.propertyExist("Name") && cr.propertyExist("Address") && cr.propertyExist("Answer");
	EXPECT_TRUE(exist);
	}

TEST(Config, PropertyExistWithSpaces)
	{
	ConfigReader cr(String(" Name=Sherlock Holmes\n Address = Baker Street, 221 b\n\tAnswer\t =42"));
	bool exist = cr.propertyExist("Name") && cr.propertyExist("Address") && cr.propertyExist("Answer");
	EXPECT_TRUE(exist);
	}

TEST(Config, PropertyExistNotExist)
	{
	ConfigReader cr(String("Name=Sherlock Holmes\nAddress = Baker Street, 221 b\nAnswer =42"));
	bool exist = cr.propertyExist("Question");
	EXPECT_FALSE(exist);
	}

TEST(Config, GetStringOnEmpty)
	{
	ConfigReader cr(String::emptyString);
	String val = cr.getString("hello");
	EXPECT_TRUE(val.empty());
	}

TEST(Config, GetStringNotExist)
	{
	ConfigReader cr(String("Name=Sherlock Holmes\nAddress = Baker Street, 221 b\nAnswer =42"));
	String val = cr.getString("Question");
	EXPECT_TRUE(val.empty());
	}

TEST(Config, GetStringOneWord)
	{
	ConfigReader cr(String("Name=Sherlock Holmes\nAddress = Baker Street, 221 b\nAnswer =42"));
	String val = cr.getString("Answer");
	EXPECT_EQ(String("42"), val);
	}

TEST(Config, GetStringValueWithSpaces)
	{
	ConfigReader cr(String("Name=Sherlock Holmes\nAddress = Baker Street, 221 b\nAnswer =42"));
	String val = cr.getString("Address");
	EXPECT_EQ(String("Baker Street, 221 b"), val);
	}

TEST(Config, GetStringMultiwordKey)
	{
	ConfigReader cr(String("\t my value\t= some string... "));
	String val = cr.getString("my value");
	EXPECT_EQ(String("some string..."), val);
	}

TEST(Config, GetStringWithEmptyLines)
	{
	ConfigReader cr(String("Name=Sherlock Holmes\n\nAddress = Baker Street, 221 b\n\n\nAnswer =42"));
	String val = cr.getString("Answer");
	EXPECT_EQ(String("42"), val);
	}

TEST(Config, GetIntOnEmpty)
	{
	ConfigReader cr(String::emptyString);
	int val = cr.getInt("key");
	EXPECT_EQ(0, val);
	}

TEST(Config, GetIntOnSingleEntry)
	{
	ConfigReader cr(String(" pi = 31415926"));
	int val = cr.getInt("pi");
	EXPECT_EQ(31415926, val);
	}

TEST(Config, GetIntOnMultiline)
	{
	ConfigReader cr(String("Name=Sherlock Holmes\n\nAddress = Baker Street, 221 b\n\n\nAnswer =42"));
	int val = cr.getInt("Answer");
	EXPECT_EQ(42, val);
	}

TEST(Config, GetArrayOnEmpty)
	{
	ConfigReader cr(String::emptyString);
	std::vector<String> arr = cr.getArray("Something");
	EXPECT_TRUE(arr.empty());
	}

TEST(Config, GetArrayOnAnotherEntry)
	{
	ConfigReader cr(String("Name=Sherlock Holmes\n\nAddress = [Baker Street, 221 b]\n\n\nAnswer =42"));
	std::vector<String> arr = cr.getArray("Question");
	EXPECT_TRUE(arr.empty());
	}

TEST(Config, GetArraySingleElemSize)
	{
	ConfigReader cr(String("Answers=[ 42 ]"));
	std::vector<String> arr = cr.getArray("Answers");
	EXPECT_EQ(1U, arr.size());
	}

TEST(Config, GetArraySingleElemValue)
	{
	ConfigReader cr(String("Answers=[ 42 ]"));
	std::vector<String> arr = cr.getArray("Answers");
	EXPECT_EQ(String("42"), arr[0]);
	}

TEST(Config, GetArrayMultiElemSingleWord)
	{
	ConfigReader cr(String("Name=Sherlock Holmes\n\nAddress = [Baker, Street, 221, b]\n\n\nAnswer =42"));
	std::vector<String> arr = cr.getArray("Address");
	ASSERT_EQ(4U, arr.size());
	EXPECT_EQ(String("Baker"), arr[0]);
	EXPECT_EQ(String("Street"), arr[1]);
	EXPECT_EQ(String("221"), arr[2]);
	EXPECT_EQ(String("b"), arr[3]);
	}

TEST(Config, GetArrayMultiElemMultiWord)
	{
	ConfigReader cr(String("Name=Sherlock Holmes\n\nAddress = [Baker Street, 221 b]\n\n\nAnswer =42"));
	std::vector<String> arr = cr.getArray("Address");
	ASSERT_EQ(2U, arr.size());
	EXPECT_EQ(String("Baker Street"), arr[0]);
	EXPECT_EQ(String("221 b"), arr[1]);
	}
