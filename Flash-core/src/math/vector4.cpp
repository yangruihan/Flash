#include "vector4.h"

namespace flash
{
    namespace math
    {
        vector4::vector4()
        {
            m_X = 0.0f;
            m_Y = 0.0f;
            m_Z = 0.0f;
            m_W = 0.0f;
        }

        vector4::vector4(const float& x, const float& y)
        {
            m_X = x;
            m_Y = y;
            m_Z = 0.0f;
            m_W = 0.0f;
        }

        vector4::vector4(const float& x, const float& y, const float& z)
        {
            m_X = x;
            m_Y = y;
            m_Z = z;
            m_W = 0.0f;
        }

        vector4::vector4(const float& x, const float& y, const float& z, const float& w)
        {
            m_X = x;
            m_Y = y;
            m_Z = z;
            m_W = w;
        }

        vector4::~vector4()
        {
        }

        vector4& vector4::add(const vector4& other)
        {
            m_X += other.m_X;
            m_Y += other.m_Y;
            m_Z += other.m_Z;
            m_W += other.m_W;
            return *this;
        }

        vector4& vector4::subtract(const vector4& other)
        {
            m_X -= other.m_X;
            m_Y -= other.m_Y;
            m_Z -= other.m_Z;
            m_W -= other.m_W;
            return *this;
        }

        vector4& vector4::multiply(const vector4& other)
        {
            m_X *= other.m_X;
            m_Y *= other.m_Y;
            m_Z *= other.m_Z;
            m_W *= other.m_W;
            return *this;
        }

        vector4& vector4::divide(const vector4& other)
        {
            m_X /= other.m_X;
            m_Y /= other.m_Y;
            m_Z /= other.m_Z;
            m_W /= other.m_W;
            return *this;
        }

        bool vector4::operator==(const vector4& other) const
        {
            return other.m_X == m_X 
                   && other.m_Y == m_Y
                   && other.m_Z == m_Z
                   && other.m_W == m_W;
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
            stream << "(" << vector4.m_X 
                   << ", " << vector4.m_Y 
                   << ", " << vector4.m_Z 
                   << ", " << vector4.m_W
                   << ")" << std::endl;
            return stream;
        }

        std::istream& operator>>(std::istream& stream, vector4& vector4)
        {
            stream >> vector4.m_X;
            stream >> vector4.m_Y;
            stream >> vector4.m_Z;
            stream >> vector4.m_W;
            return stream;
        }
    }
}