#pragma once

#include <iostream>

namespace flash
{
    namespace math
    {
        struct vector4
        {
        private:
            float m_X, m_Y, m_Z, m_W;

        public:
            vector4();
            vector4(const float& x, const float& y);
            vector4(const float& x, const float& y, const float& z);
            vector4(const float& x, const float& y, const float& z, const float& w);
            
            ~vector4();

            inline void setX(const float& x) { m_X = x; }
            inline void setY(const float& y) { m_Y = y; }
            inline void setZ(const float& z) { m_Z = z; }
            inline void setW(const float& w) { m_W = w; }

            inline float getX() const { return m_X; }
            inline float getY() const { return m_Y; }
            inline float getZ() const { return m_Z; }
            inline float getW() const { return m_W; }

            vector4& add(const vector4& other);
            vector4& subtract(const vector4& other);
            vector4& multiply(const vector4& other);
            vector4& divide(const vector4& other);

            bool operator==(const vector4& other) const;
            bool operator!=(const vector4& other) const;

            vector4& operator+=(const vector4& other);
            vector4& operator-=(const vector4& other);
            vector4& operator*=(const vector4& other);
            vector4& operator/=(const vector4& other);

            friend vector4 operator+(vector4 left, const vector4& right);
            friend vector4 operator-(vector4 left, const vector4& right);
            friend vector4 operator*(vector4 left, const vector4& right);
            friend vector4 operator/(vector4 left, const vector4& right);

            friend std::ostream& operator<<(std::ostream& stream, const vector4& vector4);
            friend std::istream& operator>>(std::istream& stream, vector4& vector4);
        };
    }
}