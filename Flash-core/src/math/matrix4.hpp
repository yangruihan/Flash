#pragma once

#include "vector3.h"
#include "vector4.h"
#include "math_func.hpp"

namespace flash
{
    namespace math
    {
        struct matrix4
        {
        private:
            union
            {
                float m_Elements[4 * 4];
                vector4 m_Columns[4];
            };

        public:
            matrix4();
            matrix4(float diagonal);
            ~matrix4();

            vector4 getColumn(int index)
            {
                index *= 4;
                return vector4(m_Elements[index],
                               m_Elements[index + 1],
                               m_Elements[index + 2],
                               m_Elements[index + 3]);
            }

            matrix4& multiply(const matrix4& other);
            matrix4& operator*=(const matrix4& other);
            friend matrix4 operator*(matrix4 left, const matrix4& right);

            static matrix4 identity();
            static matrix4 orthographic(float left, float right, 
                                        float bottom, float top,
                                        float near, float far);
            static matrix4 perspective(float fov, float aspectRatio,
                                       float near, float far);

            static matrix4 translation(const vector3& translation);
            static matrix4 rotation(float angle, const vector3& axis);
            static matrix4 scale(const vector3& scale);
        };
    }
}