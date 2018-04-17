#include "vector4.hpp"

namespace flash
{
    namespace math
    {
        vector4::vector4()
        {
            this->x = 0.0f;
            this->y = 0.0f;
            this->z = 0.0f;
            this->w = 0.0f;
        }

        vector4::vector4(const float& x, const float& y)
        {
            this->x = x;
            this->y = y;
            this->z = 0.0f;
            this->w = 0.0f;
        }

        vector4::vector4(const float& x, const float& y, const float& z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = 0.0f;
        }

        vector4::vector4(const float& x, const float& y, const float& z, const float& w)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }

        vector4::~vector4() = default;

        vector4& vector4::add(const vector4& other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
            w += other.w;
            return *this;
        }

        vector4& vector4::subtract(const vector4& other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            w -= other.w;
            return *this;
        }

        vector4& vector4::multiply(const vector4& other)
        {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            w *= other.w;
            return *this;
        }

        vector4& vector4::divide(const vector4& other)
        {
            x /= other.x;
            y /= other.y;
            z /= other.z;
            w /= other.w;
            return *this;
        }

        bool vector4::operator==(const vector4& other) const
        {
            return other.x == x 
                   && other.y == y
                   && other.z == z
                   && other.w == w;
        }

        bool vector4::operator!=(const vector4& other) const
        {
            return !(*this == other);
        }

        vector4& vector4::operator+=(const vector4& other)
        {
            return add(other);
        }

        vector4& vector4::operator-=(const vector4& other)
        {
            return subtract(other);
        }

        vector4& vector4::operator*=(const vector4& other)
        {
            return multiply(other);
        }

        vector4& vector4::operator/=(const vector4& other)
        {
            return divide(other);
        }

        vector4 operator+(vector4 left, const vector4& right)
        {
            return left.add(right);
        }

        vector4 operator-(vector4 left, const vector4& right)
        {
            return left.subtract(right);
        }

        vector4 operator*(vector4 left, const vector4& right)
        {
            return left.multiply(right);
        }

        vector4 operator/(vector4 left, const vector4& right)
        {
            return left.divide(right);
        }

        std::ostream& operator<<(std::ostream& stream, const vector4& vector4)
        {
            stream << "(" << vector4.x 
                   << ", " << vector4.y 
                   << ", " << vector4.z 
                   << ", " << vector4.w
                   << ")" << std::endl;
            return stream;
        }

        std::istream& operator>>(std::istream& stream, vector4& vector4)
        {
            stream >> vector4.x;
            stream >> vector4.y;
            stream >> vector4.z;
            stream >> vector4.w;
            return stream;
        }
    }
}