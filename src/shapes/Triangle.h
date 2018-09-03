#pragma once

#include <glm/glm.hpp>
#include "Shape.h"

namespace atum
{
class Triangle : public Shape
{
   public:
    Triangle(glm::vec3* positions);
    Triangle(glm::vec3* positions, glm::vec3* normals);
    bool Intersect(const Ray& ray, SurfaceInteraction& interaction);
    float Area();
    ~Triangle();

   private:
    glm::vec3 m_vertices[3];
    glm::vec3 m_normals[3];
};
}  // namespace atum
