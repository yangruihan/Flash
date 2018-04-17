#pragma once

#include <iostream>

namespace flash
{
    namespace math
    {
        struct vector2
        {
        public:
            float x, y;

        public:
            vector2();
            vector2(const float& x, const float& y);
            
            ~vector2();

            vector2& add(const vector2& other);
            vector2& subtract(const vector2& other);
            vector2& multiply(const vector2& other);
            vector2& divide(const vector2& other);

            bool operator==(const vector2& other) const;
            bool operator!=(const vector2& other) const;

            float& operator[](const size_t i)
            {
                switch (i)
                {
                case 0:
                    return x;
                case 1:
                    return y;
                default: 
                    // todo create exception class to replace this
                    throw "index out of range";
                }
            }

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