 #pragma once

#include <glm/vec3.hpp>

namespace atum {

class Ray
{
public:
    Ray(glm::vec3 origin, glm::vec3 direction);
public:
    glm::vec3 origin;
    glm::vec3 direction;
};

}
