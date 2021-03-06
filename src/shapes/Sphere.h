#pragma once

#include <glm/glm.hpp>
#include "Shape.h"

namespace atum
{
class Sphere : public Shape
{
   public:
    Sphere(float radius, glm::vec3 center = glm::vec3(0.f));
    bool Intersect(const Ray& ray, SurfaceInteraction& interaction);
    float Area();
    ~Sphere();

   private:
    glm::vec3 m_center;
    float m_radius;
};
}  // namespace atum
