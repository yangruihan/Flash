#pragma once

#include <iostream>

namespace flash
{
    namespace math
    {
        struct vector2
        {
        private:
            float m_X, m_Y;

        public:
            vector2();
            vector2(const float& x, const float& y);
            
            ~vector2();

            inline void setX(const float& x) { m_X = x; }
            inline void setY(const float& y) { m_Y = y; }
            inline float getX() { return m_X; }
            inline float getY() { return m_Y; }

            vector2& add(const vector2& other);
            vector2& subtract(const vector2& other);
            vector2& multiply(const vector2& other);
            vector2& divide(const vector2& other);

            bool operator==(const vector2& other) const;
            bool operator!=(const vector2& other) const;

            vector2& operator+=(const vector2& other);
            vector2& operator-=(const vector2& other);
            vector2& operator*=(const vector2& other);
            vector2& operator/=(const vector2& other);

            friend vector2 operator+(vector2 left, const vector2& right);
            friend vector2 operator-(vector2 left, const vector2& right);
            friend vector2 operator*(vector2 left, const vector2& right);
            friend vector2 operator/(vector2 left, const vector2& right);

            friend std::ostream& operator<<(std::ostream& stream, const vector2& vector2);
            friend std::istream& operator>>(std::istream& stream, vector2& vector2);
        };
    }
}