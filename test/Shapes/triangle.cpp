// unittest_SimpleMath.cpp : Defines the entry point for the console application.

#include <gtest/gtest.h>

#include <intersection/Interaction.h>
#include <intersection/Ray.h>
#include <shapes/Triangle.h>
#include <utils/Math.h>

#include <iostream>

using namespace atum;

TEST(testTriangle, Area)
{
    glm::vec3 vertices[3]{glm::vec3(1, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)};

    Triangle triangle(vertices);

    EXPECT_EQ(triangle.Area(), .5f);
}

TEST(testTriangle, Intersection_1)
{
    glm::vec3 vertices[3]{glm::vec3(0, 1, 0), glm::vec3(-1, -1, 0), glm::vec3(1, -1, 0)};

    Triangle triangle(vertices);
    Ray ray(glm::vec3(0, 0, 1), glm::vec3(0, 0, -1));
    SurfaceInteraction its;
    bool result = triangle.Intersect(ray, its);

    EXPECT_TRUE(result);                   // Intersection true
    EXPECT_EQ(its.t, 1.f);                 // Intersection distance
    EXPECT_EQ(its.wo, ray.direction);      // Intersection incidence dir
    EXPECT_EQ(its.p, glm::vec3(0));        // Intersection point
    EXPECT_EQ(its.n, glm::vec3(0, 0, 1));  // Intersection normal
    EXPECT_EQ(its.shape, &triangle);       // Intersection shape
}

int main(int argc, char** argv)
{
    // The following line must be executed to initialize Google Mock
    // (and Google Test) before running the tests.
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
