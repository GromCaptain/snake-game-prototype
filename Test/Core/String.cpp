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

TEST(String, EmptyByCopyConstructor)
	{
	String s1;
	String s2(s1);
	EXPECT_TRUE(s2.empty()) << "String(String()) is not empty";
	}

TEST(String, EmptyStaticConst)
	{
	String s = String::emptyString;
	EXPECT_TRUE(s.empty()) << "const String::emptyString is not actually empty";
	}

TEST(String, NotEmpty)
	{
	String s("abc");
	EXPECT_FALSE(s.empty()) << "String(\"abc\") is empty";
	}

TEST(String, EmptyLength)
	{
	String s;
	unsigned len = s.length();
	EXPECT_EQ(0u, len) << "Length of empty string not equal to 0";
	}

TEST(String, Length)
	{
	String s = "Humpty Dumpty";
	unsigned len = s.length();
	EXPECT_EQ(13u, len) << "Wrong length of string";
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
	ASSERT_EQ(1u, words.size());
	EXPECT_EQ(String("Hello, world!"), words.front());
	}

TEST(String, SplitByComma)
	{
	String s("Hello,World,Yep!");
	auto words = s.split(String(","));
	ASSERT_EQ(3u, words.size());
	EXPECT_EQ(String("Hello"), words[0]);
	EXPECT_EQ(String("World"), words[1]);
	EXPECT_EQ(String("Yep!"), words[2]);
	}

TEST(String, SplitByWord)
	{
	String s("abcDEFghijDEFklm");
	auto words = s.split(String("DEF"));
	ASSERT_EQ(3u, words.size());
	EXPECT_EQ(String("abc"), words[0]);
	EXPECT_EQ(String("ghij"), words[1]);
	EXPECT_EQ(String("klm"), words[2]);
	}

TEST(String, SplitNewLineNoEffect)
	{
	String s("Hello! \t");
	auto words = s.splitNewLine();
	ASSERT_EQ(1u, words.size());
	EXPECT_EQ(String("Hello! \t"), words.front());
	}

TEST(String, SplitNewLine)
	{
	String s("This!\nIs!\nThe\nString!!!");
	auto words = s.splitNewLine();
	ASSERT_EQ(4u, words.size());
	EXPECT_EQ(String("This!"), words[0]);
	EXPECT_EQ(String("Is!"), words[1]);
	EXPECT_EQ(String("The"), words[2]);
	EXPECT_EQ(String("String!!!"), words[3]);
	}

TEST(String, JoinEmptyArray)
	{
	std::vector<String> emptyArr;
	auto s = String::join(emptyArr, "!");
	EXPECT_TRUE(s.empty());
	}

TEST(String, JoinSingleEmptyString)
	{
	std::vector<String> arr = {""};
	auto s = String::join(arr, "!");
	EXPECT_TRUE(s.empty());
	}

TEST(String, JoinEmptyStrings)
	{
	std::vector<String> arr = {"", "", ""};
	auto s = String::join(arr, "!");
	EXPECT_EQ(String("!!"), s);
	}

TEST(String, JoinBySingleChar)
	{
	std::vector<String> arr = {"", "ABC", "", "deF"};
	auto s = String::join(arr, "?");
	EXPECT_EQ(String("?ABC??deF"), s);
	}

TEST(String, JoinByString)
	{
	std::vector<String> arr = {"12a", "bc3", "", "", "DEF789"};
	auto s = String::join(arr, "-+-");
	EXPECT_EQ(String("12a-+-bc3-+--+--+-DEF789"), s);
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

TEST(String, FromInt)
	{
	String s = String::fromInt(42);
	EXPECT_EQ(String("42"), s);
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

TEST(String, ConcatBothEmpty)
	{
	String s1, s2;
	s1 += s2;
	EXPECT_TRUE(s1.empty());
	}

TEST(String, ConcatEmptyAndString)
	{
	String s1;
	String s2 = "Hi!";
	s1 += s2;
	EXPECT_EQ(String("Hi!"), s1);
	}

TEST(String, ConcatStringAndEmpty)
	{
	String s1 = "FizzBuzz";
	String s2;
	s1 += s2;
	EXPECT_EQ(String("FizzBuzz"), s1);
	}

TEST(String, Concat)
	{
	String s1 = "Fizz", s2 = "Buzz";
	s1 += s2;
	EXPECT_EQ(String("FizzBuzz"), s1);
	}

TEST(String, PlusBothEmpty)
	{
	String s1, s2;
	String s = s1 + s2;
	EXPECT_TRUE(s.empty());
	}

TEST(String, PlusEmptyAndString)
	{
	String s1;
	String s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	String s = s1 + s2;
	EXPECT_EQ(String("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"), s);
	}

TEST(String, PlusStringAndEmpty)
	{
	String s1 = "I am the very model";
	String s2 = "";
	String s = s1 + s2;
	EXPECT_EQ(String("I am the very model"), s);
	}

TEST(String, Plus)
	{
	String s1 = "I am the very model\n", s2 = "Of the modern major-general!";
	String s = s1 + s2;
	EXPECT_EQ(String("I am the very model\nOf the modern major-general!"), s);
	}
