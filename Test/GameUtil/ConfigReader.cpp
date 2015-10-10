#include <gtest/gtest.h>
#include "GameUtil/ConfigReader.h"

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
