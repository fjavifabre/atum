#pragma once

namespace atum
{
class Ray;
class SurfaceInteraction;
}

namespace atum
{
class Shape
{
public:
    virtual ~Shape() = default;
    virtual bool Intersect(const Ray& ray, SurfaceInteraction& surface) = 0;
    virtual float Area() = 0;
};
}

