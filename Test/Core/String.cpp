#include <gtest/gtest.h>
#include "Core/String.h"

TEST(String, EmptyByDefaultConstructor)
	{
	String s;
	EXPECT_TRUE(s.empty()) << "String() is not empty";
	}

TEST(String, EmptyByZeroLengthInitString)
	{
	String s("");
	EXPECT_TRUE(s.empty()) << "String(\"\") is not empty";
	}

TEST(String, NotEmpty)
	{
	String s("abc");
	EXPECT_FALSE(s.empty()) << "String(\"abc\") is empty";
	}

TEST(String, SubstrEmptyTail)
	{
	String s("Hello");
	String ss = s.substr(5);
	EXPECT_TRUE(ss.empty()) << "Substring \"Hello\"[5-...] is not empty";
	}

TEST(String, SubstrTail)
	{
	String s("Hello, world!");
	String ss = s.substr(7);
	EXPECT_EQ(String("world!"), ss) << "Substring \"Hello, world!\"[7-...] is not equal to \"world!\"";
	}

TEST(String, SubstrRangeEmpty)
	{
	String s("Hello");
	String ss = s.substr(3, 0);
	EXPECT_TRUE(ss.empty()) << "Substring \"Hello\"[3 - +0] is not empty";
	}

TEST(String, SubstrRange)
	{
	String s("Hello, world!");
	String ss = s.substr(7, 5);
	EXPECT_EQ(String("world"), ss) << "Substring \"Hello, world!\"[7 - +5] is not equal to \"world\"";
	}

TEST(String, TrimNoEffect)
	{
	String s("Hello, world!");
	String ss = s.trim();
	EXPECT_EQ(s, ss) << "Trim of \"Hello, world!\" changed string";
	}

TEST(String, TrimLeftSpaces)
	{
	String s("   Hello");
	String ss = s.trim();
	EXPECT_EQ(String("Hello"), ss);
	}

TEST(String, TrimRightTab)
	{
	String s("Hello\t");
	String ss = s.trim();
	EXPECT_EQ(String("Hello"), ss);
	}

TEST(String, TrimBothSides)
	{
	String s(" \t Hello\t\t ");
	String ss = s.trim();
	EXPECT_EQ(String("Hello"), ss);
	}

TEST(String, SplitNoEffect)
	{
	String s("Hello, world!");
	auto words = s.split(String("abc"));
	EXPECT_TRUE(words.size() == 1 && words.front() == s);
	}

TEST(String, SplitByComma)
	{
	String s("Hello,World,Yep!");
	auto words = s.split(String(","));
	EXPECT_TRUE(words.size() == 3 && words.front() == String("Hello") && words.back() == String("Yep!"));
	}

TEST(String, SplitByWord)
	{
	String s("abcDEFghijDEFklm");
	auto words = s.split(String("DEF"));
	EXPECT_TRUE(words.size() == 3 && words.front() == String("abc") && words.back() == String("klm"));
	}

TEST(String, FindNoOccurance)
	{
	String s("Hello");
	int pos = s.find(String("world"));
	EXPECT_LT(pos, 0);
	}

TEST(String, Find)
	{
	String s("Hello, world!");
	int pos = s.find(String("or"));
	EXPECT_EQ(8, pos);
	}

TEST(String, FindFirstOfMultipleOccurance)
	{
	String s("Hello, world!");
	int pos = s.find(String("o"));
	EXPECT_EQ(4, pos);
	}

TEST(String, ToIntNotNumber)
	{
	String s("abc");
	int n = s.toInt();
	EXPECT_EQ(0, n);
	}

TEST(String, ToIntDefault)
	{
	String s("abc");
	int n = s.toInt(42);
	EXPECT_EQ(42, n);
	}

TEST(String, ToIntIsNumber)
	{
	String s("314");
	int n = s.toInt();
	EXPECT_EQ(314, n);
	}

TEST(String, ToIntStartWithNumber)
	{
	String s("271!");
	int n = s.toInt(42);
	EXPECT_EQ(42, n);
	}

TEST(String, ToIntFromFloat)
	{
	String s("3.14");
	int n = s.toInt(42);
	EXPECT_EQ(42, n);
	}

TEST(String, LessOnEqual)
	{
	String s1("Hello"), s2("Hello");
	EXPECT_FALSE(s1 < s2);
	EXPECT_FALSE(s2 < s1);
	}

TEST(String, LessOnLonger)
	{
	String s1("Hello"), s2("Hello, world!");
	EXPECT_LT(s1, s2);
	}

TEST(String, Less)
	{
	String s1("Hello"), s2("123Hi!");
	EXPECT_LT(s2, s1);
	EXPECT_FALSE(s1 < s2);
	}

TEST(String, LessOnDiffCase)
	{
	String s1("Hello"), s2("hello");
	EXPECT_LT(s1, s2);
	EXPECT_FALSE(s2 < s1);
	}

TEST(String, EqualOnCopy)
	{
	String s1("Hello!");
	String s2 = s1;
	EXPECT_EQ(s1, s2);
	}

TEST(String, EqualOnIdentical)
	{
	String s1("Hello"), s2("Hello");
	EXPECT_EQ(s1, s2);
	}

TEST(String, EqualOnDiffCase)
	{
	String s1("Hello"), s2("hello");
	EXPECT_NE(s1, s2);
	}

TEST(String, EqualOnLonger)
	{
	String s1("Hello"), s2("Hello, world!");
	EXPECT_NE(s1, s2);
	}

TEST(String, EqualOnDifferent)
	{
	String s1("Hello"), s2("42!");
	EXPECT_NE(s1, s2);
	}
