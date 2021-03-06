#include "gtest/gtest.h"
#include <algorithm>

#include "example/utils/IRange.hpp"

using namespace example;

TEST(IRangeTest, irangeCanBeUsedInRangeFor)
{
	int a = 0;
	for (auto num : irange(0, 5))
		EXPECT_EQ(num, a++);
	EXPECT_EQ(a, 5);
}

TEST(IRangeTest, irangeCanBeUnsigned)
{
	unsigned a = 0;
	for (auto num : irange<unsigned>(0, 5))
		EXPECT_EQ(num, a++);

	EXPECT_EQ(a, 5);
}

TEST(IRangeTest, irangeWithSingleArgument)
{
	int a = 0;
	for (auto num : irange(5))
		EXPECT_EQ(num, a++);
	EXPECT_EQ(a, 5);
}
