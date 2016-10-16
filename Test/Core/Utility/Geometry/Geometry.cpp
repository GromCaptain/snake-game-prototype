#include <gtest/gtest.h>
#include "Core/Data/Geometry/Geometry.h"

TEST(Geometry, FixedOrigPosition)
	{
	auto geom = Geometry::fixed({10, 20}, {30, 40});
	EXPECT_EQ(Point(10, 20), geom.position()) << "Fixed geometry initialized with wrong position";
	}

TEST(Geometry, FixedOrigSize)
	{
	auto geom = Geometry::fixed({10, 20}, {30, 40});
	EXPECT_EQ(Size(30, 40), geom.size()) << "Fixed geometry initialized with wrong size";
	}

TEST(Geometry, FixedPositionIsntScale)
	{
	auto geom = Geometry::fixed({10, 20}, {30, 40});
	geom.resizeAfterScreen(Size(200, 200));
	EXPECT_EQ(Point(10, 20), geom.position()) << "Fixed geometry position changed arter screen resize";
	}

TEST(Geometry, FixedSizeIsntScale)
	{
	auto geom = Geometry::fixed({10, 20}, {30, 40});
	geom.resizeAfterScreen(Size(200, 200));
	EXPECT_EQ(Size(30, 40), geom.size()) << "Fixed geometry size changed arter screen resize";
	}

TEST(Geometry, ScalableOrigPosition)
	{
	auto geom = Geometry::scalable({10, 20}, {30, 40}, {50, 50});
	EXPECT_EQ(Point(5, 10), geom.position()) << "Scalable geometry initialized with wrong position";
	}

TEST(Geometry, ScalableOrigSize)
	{
	auto geom = Geometry::scalable({10, 20}, {30, 40}, {50, 50});
	EXPECT_EQ(Size(15, 20), geom.size()) << "Scalable geometry initialized with wrong size";
	}

TEST(Geometry, ScalablePositionResize)
	{
	auto geom = Geometry::scalable({10, 20}, {30, 40}, {50, 50});
	geom.resizeAfterScreen(Size(200, 500));
	EXPECT_EQ(Point(20, 100), geom.position()) << "Scalable geometry position resized wrong";
	}

TEST(Geometry, ScalableSizeResize)
	{
	auto geom = Geometry::scalable({10, 20}, {30, 40}, {50, 50});
	geom.resizeAfterScreen(Size(200, 500));
	EXPECT_EQ(Size(60, 200), geom.size()) << "Scalable geometry size resized wrong";
	}

TEST(Geometry, FixedHorScalableVertOrigPosition)
	{
	auto geom = Geometry::fixedHorizontalScalableVertical(10, 30, 20, 40, 50);
	EXPECT_EQ(Point(10, 10), geom.position()) << "FixedHorScalableVert geometry initialized with wrong position";
	}

TEST(Geometry, FixedHorScalableVertOrigSize)
	{
	auto geom = Geometry::fixedHorizontalScalableVertical(10, 30, 20, 40, 50);
	EXPECT_EQ(Size(30, 20), geom.size()) << "FixedHorScalableVert geometry initialized with wrong size";
	}

TEST(Geometry, FixedHorScalableVertPositionResize)
	{
	auto geom = Geometry::fixedHorizontalScalableVertical(10, 30, 20, 40, 50);
	geom.resizeAfterScreen(Size(200, 500));
	EXPECT_EQ(Point(10, 100), geom.position()) << "FixedHorScalableVert geometry position resized wrong";
	}

TEST(Geometry, FixedHorScalableVertSizeResize)
	{
	auto geom = Geometry::fixedHorizontalScalableVertical(10, 30, 20, 40, 50);
	geom.resizeAfterScreen(Size(200, 500));
	EXPECT_EQ(Size(30, 200), geom.size()) << "FixedHorScalableVert geometry size resized wrong";
	}

TEST(Geometry, ScalableHorFixedVertOrigPosition)
	{
	auto geom = Geometry::scalableHorizontalFixedVertical(10, 30, 50, 20, 40);
	EXPECT_EQ(Point(5, 20), geom.position()) << "ScalableHorFixedVert geometry initialized with wrong position";
	}

TEST(Geometry, ScalableHorFixedVertOrigSize)
	{
	auto geom = Geometry::scalableHorizontalFixedVertical(10, 30, 50, 20, 40);
	EXPECT_EQ(Size(15, 40), geom.size()) << "ScalableHorFixedVert geometry initialized with wrong size";
	}

TEST(Geometry, ScalableHorFixedVertPositionResize)
	{
	auto geom = Geometry::scalableHorizontalFixedVertical(10, 30, 50, 20, 40);
	geom.resizeAfterScreen(Size(200, 500));
	EXPECT_EQ(Point(20, 20), geom.position()) << "ScalableHorFixedVert geometry position resized wrong";
	}

TEST(Geometry, ScalableHorFixedVertSizeResize)
	{
	auto geom = Geometry::scalableHorizontalFixedVertical(10, 30, 50, 20, 40);
	geom.resizeAfterScreen(Size(200, 500));
	EXPECT_EQ(Size(60, 40), geom.size()) << "ScalableHorFixedVert geometry position resized wrong";
	}
