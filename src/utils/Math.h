#pragma once

namespace atum
{
class Math
{
public:
    template<typename T=float>
    static constexpr T pi = T(3.1415926535897932385L);  // variable template

    static bool SolveQuadratic(const float &a, const float &b, const float &c, float &x0, float &x1);
};
}
