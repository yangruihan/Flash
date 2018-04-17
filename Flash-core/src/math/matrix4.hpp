#pragma once

#include "vector3.hpp"
#include "vector4.hpp"
#include "math_func.hpp"

namespace flash
{
    namespace math
    {
        struct matrix4
        {
        public:
            union
            {
                float elements[4 * 4] {};
                vector4 columns[4];
            };

        public:
            matrix4();
            matrix4(const float diagonal);
            ~matrix4();

            float get_element(const size_t x, const size_t y) { return elements[x * 4 + y]; }
            vector4 get_column(const size_t index) { return columns[index]; }

            matrix4& multiply(const matrix4& other);
            matrix4& operator*=(const matrix4& other);

            vector4& operator[](const size_t i)
            {
                switch (i)
                {
                case 0:
                case 1:
                case 2:
                case 3:
                    return columns[i];
                default:
                    // todo create exception class to replace this
                    throw "index out of range";
                }
            }

            friend matrix4 operator*(matrix4 left, const matrix4& right);

            static matrix4 identity();
            static matrix4 orthographic(float left,   float right, 
                                        float bottom, float top,
                                        float near,   float far);
            static matrix4 perspective(float fov,  float aspectRatio,
                                       float near, float far);

            static matrix4 translation(const vector3& translation);
            static matrix4 rotation(float angle, const vector3& axis);
            static matrix4 scale(const vector3& scale);
        };
    }
}