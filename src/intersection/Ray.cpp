#include "Ray.h"

namespace atum
{
    Ray::Ray(glm::vec3 _origin, glm::vec3 _direction)
        : origin(_origin),
          direction(_direction)
    {
        // TODO: assert is directon is normalized
    }
}
