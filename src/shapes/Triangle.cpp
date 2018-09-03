#include "Triangle.h"

#include <intersection/Interaction.h>
#include <intersection/Ray.h>
#include <algorithm>

namespace atum
{
Triangle::Triangle(glm::vec3* positions)
{
    m_vertices[0] = positions[0];
    m_vertices[1] = positions[1];
    m_vertices[2] = positions[2];

    // Calculate normal of the triangle and repeat
    m_normals[0] = m_normals[1] = m_normals[2] =
        glm::normalize(glm::cross(m_vertices[1] - m_vertices[0], m_vertices[2] - m_vertices[0]));
}

Triangle::Triangle(glm::vec3* positions, glm::vec3* normals)
{
    m_vertices[0] = positions[0];
    m_vertices[1] = positions[1];
    m_vertices[2] = positions[2];

    m_normals[0] = normals[0];
    m_normals[1] = normals[1];
    m_normals[2] = normals[2];
}

float Triangle::Area()
{
    return .5f * glm::length(glm::cross(m_vertices[1] - m_vertices[0], m_vertices[2] - m_vertices[0]));
}

bool Triangle::Intersect(const Ray& ray, SurfaceInteraction& interaction)
{
    // TODO: check culling

    const float EPSILON = 0.0000001f;
    glm::vec3 edge1, edge2, h, s, q;
    float a, f, u, v;
    edge1 = m_vertices[1] - m_vertices[0];
    edge2 = m_vertices[2] - m_vertices[0];
    h = glm::cross(ray.direction, edge2);
    a = glm::dot(edge1, h);
    if (a > -EPSILON && a < EPSILON) return false;
    f = 1 / a;
    s = ray.origin - m_vertices[0];
    u = f * glm::dot(s, h);
    if (u < 0.0f || u > 1.0f) return false;
    q = glm::cross(s, edge1);
    v = f * glm::dot(ray.direction, q);
    if (v < 0.0f || u + v > 1.0f) return false;
    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * glm::dot(edge2, q);
    if (t > EPSILON)  // ray intersection
    {
        interaction.t = t;
        interaction.wo = ray.direction;
        interaction.p = ray.origin + ray.direction * t;
        interaction.n = m_normals[0];  // TODO: change when we have better normals
        interaction.shape = this;

        return true;
    } else  // This means that there is a line intersection but not a ray intersection.
        return false;
}

Triangle::~Triangle() {}
}  // namespace atum
