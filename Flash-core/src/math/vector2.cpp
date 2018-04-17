#include "vector2.hpp"

namespace flash
{
    namespace math
    {
        vector2::vector2()
        {
            x = 0.0f;
            y = 0.0f;
        }

        vector2::vector2(const float& x, const float& y)
        {
            this->x = x;
            this->y = y;
        }

        vector2::~vector2() = default;

        vector2& vector2::add(const vector2& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        vector2& vector2::subtract(const vector2& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        vector2& vector2::multiply(const vector2& other)
        {
            x *= other.x;
            y *= other.y;
            return *this;
        }

        vector2& vector2::divide(const vector2& other)
        {
            x /= other.x;
            y /= other.y;
            return *this;
        }

        bool vector2::operator==(const vector2& other) const
        {
            return other.x == x && other.y == y;
        }

        bool vector2::operator!=(const vector2& other) const
        {
            return !(*this == other);
        }

        vector2& vector2::operator+=(const vector2& other)
        {
            return add(other);
        }

        vector2& vector2::operator-=(const vector2& other)
        {
            return subtract(other);
        }

        vector2& vector2::operator*=(const vector2& other)
        {
            return multiply(other);
        }

        vector2& vector2::operator/=(const vector2& other)
        {
            return divide(other);
        }

        vector2 operator+(vector2 left, const vector2& right)
        {
            return left.add(right);
        }

        vector2 operator-(vector2 left, const vector2& right)
        {
            return left.subtract(right);
        }

        vector2 operator*(vector2 left, const vector2& right)
        {
            return left.multiply(right);
        }

        vector2 operator/(vector2 left, const vector2& right)
        {
            return left.divide(right);
        }

        std::ostream& operator<<(std::ostream& stream, const vector2& vector2)
        {
            stream << "(" << vector2.x << ", " << vector2.y << ")" << std::endl;
            return stream;
        }

        std::istream& operator>>(std::istream& stream, vector2& vector2)
        {
            stream >> vector2.x;
            stream >> vector2.y;
            return stream;
        }
    }
}