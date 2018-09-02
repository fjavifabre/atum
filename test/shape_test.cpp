// unittest_SimpleMath.cpp : Defines the entry point for the console application.

#include <gtest/gtest.h>

TEST(testMath, myCubeTest)
{
    EXPECT_EQ(1000, 10*10);
}
int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
