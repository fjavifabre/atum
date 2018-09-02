// unittest_SimpleMath.cpp : Defines the entry point for the console application.

#include <gtest/gtest.h>

#include <shapes/Sphere.h>
#include <utils/Math.h>

using namespace atum;

TEST(testSphere, Area)
{
    Sphere sphere(10.f);
    EXPECT_EQ(sphere.Area(), 4.f * Math::pi<> * 100.f);
}
int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
