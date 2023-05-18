#include "dummy/testClass.hpp"
#include <gtest/gtest.h>

TEST(DummyTest, DummyTest1)
{
    int i{0};
    EXPECT_EQ(i, 0);
}
