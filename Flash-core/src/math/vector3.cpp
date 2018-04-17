#include "vector3.hpp"

namespace flash
{
    namespace math
    {
        vector3::vector3()
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }

        vector3::vector3(const float& x, const float& y)
        {
            this->x = x;
            this->y = y;
            this->z = 0.0f;
        }

        vector3::vector3(const float& x, const float& y, const float& z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        vector3::~vector3() = default;

        vector3& vector3::add(const vector3& other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        vector3& vector3::subtract(const vector3& other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }

        vector3& vector3::multiply(const vector3& other)
        {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            return *this;
        }

        vector3& vector3::divide(const vector3& other)
        {
            x /= other.x;
            y /= other.y;
            z /= other.z;
            return *this;
        }

        bool vector3::operator==(const vector3& other) const
        {
            return other.x == x 
                   && other.y == y
                   && other.z == z;
        }

        bool vector3::operator!=(const vector3& other) const
        {
            return !(*this == other);
        }

        vector3& vector3::operator+=(const vector3& other)
        {
            return add(other);
        }

        vector3& vector3::operator-=(const vector3& other)
        {
            return subtract(other);
        }

        vector3& vector3::operator*=(const vector3& other)
        {
            return multiply(other);
        }

        vector3& vector3::operator/=(const vector3& other)
        {
            return divide(other);
        }

        vector3 operator+(vector3 left, const vector3& right)
        {
            return left.add(right);
        }

        vector3 operator-(vector3 left, const vector3& right)
        {
            return left.subtract(right);
        }

        vector3 operator*(vector3 left, const vector3& right)
        {
            return left.multiply(right);
        }

        vector3 operator/(vector3 left, const vector3& right)
        {
            return left.divide(right);
        }

        std::ostream& operator<<(std::ostream& stream, const vector3& vector3)
        {
            stream << "(" << vector3.x 
                   << ", " << vector3.y 
                   << ", " << vector3.z 
                   << ")" << std::endl;
            return stream;
        }

        std::istream& operator>>(std::istream& stream, vector3& vector3)
        {
            stream >> vector3.x;
            stream >> vector3.y;
            stream >> vector3.z;
            return stream;
        }
    }
}