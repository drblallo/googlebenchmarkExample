#include "example/utils/ScopeGuard.hpp"

#include "gtest/gtest.h"

using namespace example;

TEST(ScopeGuardTest, scopeGuardShouldRestoreInteger)
{
	int val = 4;
	{
		auto g = makeGuard([&]() { val++; });
	}

	EXPECT_EQ(val, 5);
}
