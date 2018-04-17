#pragma once

#include <iostream>

namespace flash
{
    namespace math
    {
        struct vector4
        {
        public:
            float x, y, z, w;

        public:
            vector4();
            vector4(const float& x, const float& y);
            vector4(const float& x, const float& y, const float& z);
            vector4(const float& x, const float& y, const float& z, const float& w);
            
            ~vector4();

            vector4& add(const vector4& other);
            vector4& subtract(const vector4& other);
            vector4& multiply(const vector4& other);
            vector4& divide(const vector4& other);

            bool operator==(const vector4& other) const;
            bool operator!=(const vector4& other) const;

            float& operator[](const size_t i)
            {
                switch (i)
                {
                case 0:
                    return x;
                case 1:
                    return y;
                case 2:
                    return z;
                case 3:
                    return w;
                default:
                    // todo create exception class to replace this
                    // http://en.cppreference.com/w/cpp/error/exception
                    throw "index out of range";
                }
            }

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