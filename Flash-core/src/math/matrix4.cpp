#include "matrix4.hpp"

namespace flash
{
    namespace math
    {
        matrix4::matrix4()
        {
            for (size_t i = 0; i < 4 * 4; i++)
                elements[i] = 0.0f;
        }

        matrix4::matrix4(float diagonal)
        {
            for (size_t i = 0; i < 4 * 4; i++)
                elements[i] = 0.0f;

            elements[0 + 0 * 4] = diagonal;
            elements[1 + 1 * 4] = diagonal;
            elements[2 + 2 * 4] = diagonal;
            elements[3 + 3 * 4] = diagonal;
        }

        matrix4::~matrix4()
        {
        }

        matrix4& matrix4::multiply(const matrix4& other)
        {
            for (size_t y = 0; y< 4; y++)
            {
                for (size_t x = 0; x < 4; x++)
                {
                    float sum = 0.0f;
                    for (size_t e = 0; e < 4; e++)
                    {
                        sum += elements[x + e *  4] * other.elements[e + y * 4];
                    }
                    elements[x + y * 4] = sum;
                }
            }

            return *this;
        }

        matrix4& matrix4::operator*=(const matrix4& other)
        {
            return multiply(other);
        }

        matrix4 operator*(matrix4 left, const matrix4& right)
        {
            return left.multiply(right);
        }

        matrix4 matrix4::identity()
        {
            return matrix4(1.0f);
        }

        matrix4 matrix4::orthographic(float left, float right,
                                    float bottom, float top,
                                    float near, float far)
        {
            matrix4 result(1.0f);

            result.elements[0 + 0 * 4] = 2.0f / (right - left);
            result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
            result.elements[2 + 2 * 4] = 2.0f / (near - far);
            result.elements[0 + 3 * 4] = (left + right) / (left - right);
            result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
            result.elements[2 + 3 * 4] = (far + near) / (far -near);

            return result;
        }

        matrix4 matrix4::perspective(float fov, float aspectRatio,
                                    float near, float far)
        {
            matrix4 result(1.0f);

            float q = 1.0f / tan(toRadians(0.5f * fov));
            float a = q / aspectRatio;

            float b = (near + far) / (near - far);
            float c = (2.0f * near * far) / (near - far);

            result.elements[0 + 0 * 4] = a;
            result.elements[1 + 1 * 4] = q;
            result.elements[2 + 2 * 4] = b;
            result.elements[3 + 2 * 4] = -1.0f;
            result.elements[2 + 3 * 4] = c;

            return result;
        }


        matrix4 matrix4::translation(const vector3& translation)
        {
            matrix4 result(1.0f);

            result.elements[0 + 3 * 4] = translation.getX();
            result.elements[1 + 3 * 4] = translation.getY();
            result.elements[2 + 3 * 4] = translation.getZ();

            return result;
        }

        matrix4 matrix4::rotation(float angle, const vector3& axis)
        {
            matrix4 result(1.0f);

            float r = toRadians(angle);
            float c = cos(r);
            float s = sin(r);
            float omc = 1.0f - c;

            float x = axis.getX();
            float y = axis.getY();
            float z = axis.getZ();

            result.elements[0 + 0 * 4] = x * omc + c;
            result.elements[1 + 0 * 4] = y * x * omc + z * s;
            result.elements[2 + 0 * 4] = x * z * omc - y * s;

            result.elements[0 + 1 * 4] = x * y * omc - z * s;
            result.elements[1 + 1 * 4] = y * omc + c;
            result.elements[2 + 1 * 4] = y * z * omc + x * s;

            result.elements[0 + 2 * 4] = x * z * omc + y * s;
            result.elements[1 + 2 * 4] = y * z * omc - x * s;
            result.elements[2 + 2 * 4] = z * omc + c;

            return result;
        }

        matrix4 matrix4::scale(const vector3& scale)
        {
            matrix4 result(1.0f);

            result.elements[0 + 0 * 4] = scale.getX();
            result.elements[1 + 1 * 4] = scale.getY();
            result.elements[2 + 2 * 4] = scale.getZ();

            return result;
        }
    }
}