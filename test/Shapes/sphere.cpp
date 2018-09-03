// unittest_SimpleMath.cpp : Defines the entry point for the console application.

#include <gtest/gtest.h>
#include <intersection/Interaction.h>
#include <intersection/Ray.h>
#include <shapes/Sphere.h>
#include <utils/Math.h>

using namespace atum;

TEST(testSphere, Area)
{
    Sphere sphere(10.f);
    EXPECT_EQ(sphere.Area(), 4.f * Math::pi<> * 100.f);
}

TEST(testSphere, Intersection_1)
{
    Sphere sphere(10.f);
    Ray ray(glm::vec3(0, 0, 11), glm::vec3(0, 0, -1));
    SurfaceInteraction its;
    bool result = sphere.Intersect(ray, its);

    EXPECT_TRUE(result);                    // Intersection true
    EXPECT_EQ(its.t, 1.f);                  // Intersection distance
    EXPECT_EQ(its.wo, ray.direction);       // Intersection incidence dir
    EXPECT_EQ(its.p, glm::vec3(0, 0, 10));  // Intersection point
    EXPECT_EQ(its.n, glm::vec3(0, 0, 1));   // Intersection normal
    EXPECT_EQ(its.shape, &sphere);          // Intersection shape
}

int main(int argc, char** argv)
{
    // The following line must be executed to initialize Google Mock
    // (and Google Test) before running the tests.
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
