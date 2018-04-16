#pragma once

#include <iostream>

namespace flash
{
    namespace math
    {
        struct vector3
        {
        private:
            float m_X, m_Y, m_Z;

        public:
            vector3();
            vector3(const float& x, const float& y);
            vector3(const float& x, const float& y, const float& z);
            
            ~vector3();

            inline void setX(const float& x) { m_X = x; }
            inline void setY(const float& y) { m_Y = y; }
            inline void setZ(const float& z) { m_Z = z; }

            inline float getX() { return m_X; }
            inline float getY() { return m_Y; }
            inline float getZ() { return m_Z; }

            vector3& add(const vector3& other);
            vector3& subtract(const vector3& other);
            vector3& multiply(const vector3& other);
            vector3& divide(const vector3& other);

            bool operator==(const vector3& other) const;
            bool operator!=(const vector3& other) const;

            vector3& operator+=(const vector3& other);
            vector3& operator-=(const vector3& other);
            vector3& operator*=(const vector3& other);
            vector3& operator/=(const vector3& other);

            friend vector3 operator+(vector3 left, const vector3& right);
            friend vector3 operator-(vector3 left, const vector3& right);
            friend vector3 operator*(vector3 left, const vector3& right);
            friend vector3 operator/(vector3 left, const vector3& right);

            friend std::ostream& operator<<(std::ostream& stream, const vector3& vector3);
            friend std::istream& operator>>(std::istream& stream, vector3& vector3);
        };
    }
}