#include "Interaction.h"

#include <limits>

namespace atum
{
    SurfaceInteraction::SurfaceInteraction()
        : t(std::numeric_limits<float>::infinity())
        , shape(nullptr)
    {}
}
