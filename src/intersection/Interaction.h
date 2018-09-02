#pragma once

#include <glm/vec3.hpp>

namespace atum
{
class Shape;
}

namespace atum
{
struct Interaction {
    glm::vec3 p;
    float time;
    glm::vec3 wo;
    glm::vec3 n;
};

// Surface interaction specification
class SurfaceInteraction : public Interaction
{
   public:
    SurfaceInteraction();
    // Public data
   public:
    // Distance traveled by the ray
    float t;
    // Pointer to the Shape if intersected
    Shape* shape;
};

}  // namespace atum
