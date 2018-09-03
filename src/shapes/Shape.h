#pragma once

namespace atum
{
class Ray;
class SurfaceInteraction;
}  // namespace atum

namespace atum
{
class Shape
{
   public:
    virtual ~Shape() = default;
    /**
     * @brief Intersects the Shape with the given ray
     * @param ray Ray to intersect
     * @param surface Information of the intersection
     * @return true if shape is intersected, false otherwise
     */
    virtual bool Intersect(const Ray& ray, SurfaceInteraction& surface) = 0;

    /**
     * @brief Calculates the area of the Shape
     * @return Area of this Shape
     */
    virtual float Area() = 0;
};
}  // namespace atum
