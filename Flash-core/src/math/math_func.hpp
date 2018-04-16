#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace flash
{
    namespace math
    {
        inline float toRadians(float degrees)
        {
            return degrees * ((float)M_PI / 180.0f);
        }
    }
}