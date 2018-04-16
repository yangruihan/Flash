#include "vector3.h"

namespace flash
{
    namespace math
    {
        vector3::vector3()
        {
            m_X = 0.0f;
            m_Y = 0.0f;
            m_Z = 0.0f;
        }

        vector3::vector3(const float& x, const float& y)
        {
            m_X = x;
            m_Y = y;
            m_Z = 0.0f;
        }

        vector3::vector3(const float& x, const float& y, const float& z)
        {
            m_X = x;
            m_Y = y;
            m_Z = z;
        }

        vector3::~vector3()
        {
        }

        vector3& vector3::add(const vector3& other)
        {
            m_X += other.m_X;
            m_Y += other.m_Y;
            m_Z += other.m_Z;
            return *this;
        }

        vector3& vector3::subtract(const vector3& other)
        {
            m_X -= other.m_X;
            m_Y -= other.m_Y;
            m_Z -= other.m_Z;
            return *this;
        }

        vector3& vector3::multiply(const vector3& other)
        {
            m_X *= other.m_X;
            m_Y *= other.m_Y;
            m_Z *= other.m_Z;
            return *this;
        }

        vector3& vector3::divide(const vector3& other)
        {
            m_X /= other.m_X;
            m_Y /= other.m_Y;
            m_Z /= other.m_Z;
            return *this;
        }

        bool vector3::operator==(const vector3& other) const
        {
            return other.m_X == m_X 
                   && other.m_Y == m_Y
                   && other.m_Z == m_Z;
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
            stream << "(" << vector3.m_X 
                   << ", " << vector3.m_Y 
                   << ", " << vector3.m_Z 
                   << ")" << std::endl;
            return stream;
        }

        std::istream& operator>>(std::istream& stream, vector3& vector3)
        {
            stream >> vector3.m_X;
            stream >> vector3.m_Y;
            stream >> vector3.m_Z;
            return stream;
        }
    }
}