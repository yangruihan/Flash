#pragma once

#include <iostream>

namespace flash
{
    namespace math
    {
        struct vector3
        {
        public:
            float x, y, z;

        public:
            vector3();
            vector3(const float& x, const float& y);
            vector3(const float& x, const float& y, const float& z);
            
            ~vector3();

            vector3& add(const vector3& other);
            vector3& subtract(const vector3& other);
            vector3& multiply(const vector3& other);
            vector3& divide(const vector3& other);

            bool operator==(const vector3& other) const;
            bool operator!=(const vector3& other) const;

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
                default: 
                    // todo create exception class to replace this
                    // http://en.cppreference.com/w/cpp/error/exception
                    throw "index out of range";
                }
            }

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