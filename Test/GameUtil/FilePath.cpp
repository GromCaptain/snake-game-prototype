#include <gtest/gtest.h>
#include "GameUtil/FilePath.h"

TEST(FilePath, CreateEmpty)
	{
	FilePath p(String::emptyString);
	String s = p.string();
	EXPECT_TRUE(s.empty());
	}

TEST(FilePath, CreateSingleElement)
	{
	FilePath p(String("myfile"));
	String s = p.string();
	EXPECT_EQ(String("myfile"), s);
	}

TEST(FilePath, CreateSingleElementWithExtension)
	{
	FilePath p(String("anotherFile.txt"));
	String s = p.string();
	EXPECT_EQ(String("anotherFile.txt"), s);
	}

TEST(FilePath, CreateWithMainSeparator)
	{
	FilePath p(String("dir/subdir/subsubdir/file.txt"));
	String s = p.string();
	EXPECT_EQ(String("dir/subdir/subsubdir/file.txt"), s);
	}

TEST(FilePath, CreateWithAdditionalSeparator)
	{
	FilePath p(String("dir\\subdir\\subsubdir\\file.txt"));
	String s = p.string();
	EXPECT_EQ(String("dir/subdir/subsubdir/file.txt"), s);
	}

TEST(FilePath, CreateWithBothSeparators)
	{
	FilePath p(String("dir/subdir\\subsubdir\\file.txt"));
	String s = p.string();
	EXPECT_EQ(String("dir/subdir/subsubdir/file.txt"), s);
	}

TEST(FilePath, CreateStartedMainSeparator)
	{
	FilePath p(String("/dir\\subdir/subsubdir\\file.txt"));
	String s = p.string();
	EXPECT_EQ(String("dir/subdir/subsubdir/file.txt"), s);
	}

TEST(FilePath, CreateStartedWithAdditionalSeparator)
	{
	FilePath p(String("\\dir/subdir\\subsubdir/file.txt"));
	String s = p.string();
	EXPECT_EQ(String("dir/subdir/subsubdir/file.txt"), s);
	}

TEST(FilePath, CreateEndedWithMainSeparator)
	{
	FilePath p(String("\\dir/subdir\\subsubdir/"));
	String s = p.string();
	EXPECT_EQ(String("dir/subdir/subsubdir"), s);
	}

TEST(FilePath, CreateEndedWithAdditionalSeparator)
	{
	FilePath p(String("/dir/subdir\\subsubdir\\"));
	String s = p.string();
	EXPECT_EQ(String("dir/subdir/subsubdir"), s);
	}

TEST(FilePath, CreateContainsOnlyTwoSeparators)
	{
	FilePath p(String("\\/"));
	String s = p.string();
	EXPECT_TRUE(s.empty());
	}

TEST(FilePath, CreateUp)
	{
	FilePath p(String(".."));
	String s = p.string();
	EXPECT_EQ(String(".."), s);
	}

TEST(FilePath, CreateUp3Times)
	{
	FilePath p(String("../..\\.."));
	String s = p.string();
	EXPECT_EQ(String("../../.."), s);
	}

TEST(FilePath, CreateUpAndFolder)
	{
	FilePath p(String("/..\\hello"));
	String s = p.string();
	EXPECT_EQ(String("../hello"), s);
	}

TEST(FilePath, CreateFolderAndUp)
	{
	FilePath p(String("hi\\..\\"));
	String s = p.string();
	EXPECT_TRUE(s.empty());
	}

TEST(FilePath, CreateMultipleFoldersAndUps)
	{
	FilePath p(String("folder1\\folder2/folder3/../../sub"));
	String s = p.string();
	EXPECT_EQ(String("folder1/sub"), s);
	}

TEST(FilePath, CreateMixedFoldersAndUps)
	{
	FilePath p(String("aaa/bbb\\../ccc/ddd\\..\\ee/../../xxx.yyy"));
	String s = p.string();
	EXPECT_EQ(String("aaa/xxx.yyy"), s);
	}

TEST(FilePath, CreateUpsInTotal)
	{
	FilePath p(String("aaa/../bbb/../../../ccc/../.."));
	String s = p.string();
	EXPECT_EQ(String("../../.."), s);
	}

TEST(FilePath, FolderPathFromEmpty)
	{
	FilePath p(String::emptyString);
	String s = p.folderPath().string();
	EXPECT_EQ(String(".."), s);
	}

TEST(FilePath, FolderPathFromSingleElement)
	{
	FilePath p(String("here"));
	String s = p.folderPath().string();
	EXPECT_TRUE(s.empty());
	}

TEST(FilePath, FolderPathFromSubfolder)
	{
	FilePath p(String("xxx/yyy"));
	String s = p.folderPath().string();
	EXPECT_EQ(String("xxx"), s);
	}

TEST(FilePath, FolderPathFromComplexPath)
	{
	FilePath p(String("folder/subfolder/subsubfolder\\file.ext"));
	String s = p.folderPath().string();
	EXPECT_EQ(String("folder/subfolder/subsubfolder"), s);
	}

TEST(FilePath, FolderPathFromUps)
	{
	FilePath p(String("../.."));
	String s = p.folderPath().string();
	EXPECT_EQ(String("../../.."), s);
	}

TEST(FilePath, ConcatFolderAndFile)
	{
	FilePath p(String("folder"));
	p += String("file.txt");
	String s = p.string();
	EXPECT_EQ(String("folder/file.txt"), s);
	}

TEST(FilePath, ConcatFolderAndFilePath)
	{
	FilePath folderPath(String("folder")), filePath(String("subfolder\\xxx.yyy"));
	String s = (folderPath + filePath).string();
	EXPECT_EQ(String("folder/subfolder/xxx.yyy"), s);
	}

TEST(FilePath, ConcatFolderPathAndEmpty)
	{
	FilePath p(String("aaa\\bbb"));
	p += String("");
	String s = p.string();
	EXPECT_EQ(String("aaa/bbb"), s);
	}

TEST(FilePath, ConcatFolderPathAndFilePath)
	{
	FilePath folderPath(String("aaa/bbb\\ccc")), filePath(String("ddd/eee.zzz"));
	String s = (folderPath + filePath).string();
	EXPECT_EQ(String("aaa/bbb/ccc/ddd/eee.zzz"), s);
	}

TEST(FilePath, ConcatFolderPathAndFolderPathWithUps)
	{
	FilePath p1(String("aaa/bbb\\ccc")), p2(String("../ddd/subfolder"));
	p1 += p2;
	String s = p1.string();
	EXPECT_EQ(String("aaa/bbb/ddd/subfolder"), s);
	}

TEST(FilePath, ComplexConcat)
	{
	FilePath folderPath(String("../aa/bbb\\..")), filePath(String("../ddd/xxx.yyy"));
	String s = (folderPath + filePath).string();
	EXPECT_EQ(String("../ddd/xxx.yyy"), s);
	}

//TEST(FilePath, FolderPathWithUps)
//	{
//	FilePath
//	}
