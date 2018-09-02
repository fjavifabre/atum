#include "Sphere.h"

#include <intersection/Interaction.h>
#include <intersection/Ray.h>

#include <algorithm>

#include <utils/Math.h>

namespace atum
{
Sphere::Sphere(float radius, glm::vec3 center)
    : m_center(center)
    , m_radius(radius)

{
}

bool Sphere::Intersect(const Ray& ray, SurfaceInteraction& interaction)
{
    float t0, t1;  // solutions for t if the ray intersects

    // analytic solution
    glm::vec3 L = ray.origin - m_center;
    float a = glm::dot(ray.direction, ray.direction);  //  dir.dotProduct(dir);
    float b = 2.f * glm::dot(ray.direction, L);        // 2 * dir.dotProduct(L);
    float c = glm::dot(L, L) - m_radius * m_radius;    // L.dotProduct(L) - radius2;
    if (!Math::SolveQuadratic(a, b, c, t0, t1)) return false;

    if (t0 > t1) std::swap(t0, t1);

    if (t0 < 0) {
        t0 = t1;                   // if t0 is negative, let's use t1 instead
        if (t0 < 0) return false;  // both t0 and t1 are negative
    }

    // Fill interaction
    interaction.t = t0;
    interaction.wo = ray.direction;
    interaction.p = ray.origin + ray.direction * t0;
    interaction.n = glm::normalize(interaction.p - m_center);
    interaction.shape = this;

    return true;
}

float Sphere::Area() { return 4.f * Math::pi<> * m_radius * m_radius; }

Sphere::~Sphere() {}

}  // namespace atum
