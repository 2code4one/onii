#ifndef ONII_VECTOR2D_HPP
#define ONII_VECTOR2D_HPP

/////////////////////////////////////////////////
/// @file onii/vector2d.hpp
/////////////////////////////////////////////////

#include <cmath>
#include "float/equal.hpp"

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @class vector2d
/// @brief Class representing a 2D vector
/////////////////////////////////////////////////
class vector2d
{
public:

    float x; ///< x component
    float y; ///< y component

    /////////////////////////////////////////////////
    /// @brief Default constructor
    /////////////////////////////////////////////////
    vector2d() :
        x(0.f),
        y(0.f)
    {}

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in] x_ - x component
    /// @param[in] y_ - y component
    /////////////////////////////////////////////////
    vector2d(float x_, float y_) :
        x(x_),
        y(y_)
    {}

    /////////////////////////////////////////////////
    /// @brief Addition
    ///
    /// @param[in] rhs - The vector2d to add
    /// @return *this
    /////////////////////////////////////////////////
    vector2d &operator+=(vector2d const &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Substraction
    ///
    /// @param[in] rhs - The vector2d to substract
    /// @return *this
    /////////////////////////////////////////////////
    vector2d &operator-=(vector2d const &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Multiplication
    ///
    /// @param[in] scalar - The scalar value
    /// @return *this
    /////////////////////////////////////////////////
    vector2d &operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Get the squared length
    ///
    /// @param[in] v - vector2d to compute
    /// @return The squared length value
    /////////////////////////////////////////////////
    static float squared_lenght(vector2d const &v)
    {
        return v.x * v.x + v.y * v.y;
    }

    /////////////////////////////////////////////////
    /// @brief Get the length
    ///
    /// @param[in] v - vector2d to compute
    /// @return The length value
    /////////////////////////////////////////////////
    static float lenght(vector2d const &v)
    {
        return std::sqrt(squared_lenght(v));
    }

    /////////////////////////////////////////////////
    /// @brief Get a normalized vector2d
    ///
    /// @param[in] v - vector2d to normalize
    /// @return The normalized vector2d
    /////////////////////////////////////////////////
    static vector2d normalize(vector2d const &v)
    {
        float len = lenght(v);
        return vector2d(v.x / len, v.y / len);
    }

    /////////////////////////////////////////////////
    /// @brief Compute the dot product of two vector2ds
    ///
    /// @param[in] lhs - first vector2d
    /// @param[in] rhs - second vector2d
    /// @return The computed dot product
    /////////////////////////////////////////////////
    static float dot_product(vector2d const &lhs, vector2d const &rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    /////////////////////////////////////////////////
    /// @brief Compute the cross product of two vector2d
    ///
    /// @param[in] lhs - first vector2d
    /// @param[in] rhs - second vector2d
    /// @return The computed cross product
    /// @remarks This function return only the z component value
    ///          of the computed cross product, because this class
    ///          is only a 2D vector2d
    /////////////////////////////////////////////////
    static float cross_product_z(vector2d const &lhs, vector2d const &rhs)
    {
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }

    /////////////////////////////////////////////////
    /// @brief Get the orthogonal vector2d
    ///
    /// @param[in] v - the vector2d
    /// @return A orthogonal vector2d of v
    /// @remarks The orthogonal vector2d is computed
    ///          like this: @code (v.y -v.x) @endcode
    /////////////////////////////////////////////////
    static vector2d orthogonal_x(vector2d const &v)
    {
        return vector2d(v.y, -v.x);
    }

    /////////////////////////////////////////////////
    /// @brief Get the orthogonal vector2d
    ///
    /// @param[in] v - the vector2d
    /// @return A orthogonal vector2d of v
    /// @remarks The orthogonal vector2d is computed
    ///          like this: @code (-v.y v.x) @endcode
    /////////////////////////////////////////////////
    static vector2d orthogonal_y(vector2d const &v)
    {
        return vector2d(-v.y, v.x);
    }

    /////////////////////////////////////////////////
    /// @brief Rotate a vector2d with a given angle
    ///
    /// @param[in] v - vector2d to rotate
    /// @param[in] angle - the rotation angle
    /// @return the rotated vector2d
    /// @remarks The rotation is counter-clockwise
    /////////////////////////////////////////////////
    static vector2d rotate(vector2d const &v, unit::angle const &angle)
    {
        float c = std::cos(angle.rad());
        float s = std::sin(angle.rad());
        return vector2d(v.x * c - v.y * s, v.x * s + v.y * c);
    }

}; // class vector2d

/////////////////////////////////////////////////
/// @brief Get a positive vector2d
///
/// @param[in] v - vector2d
/// @return The same vector2d as v
/// @relates vector2d
/////////////////////////////////////////////////
vector2d operator+(vector2d const &v)
{
    return vector2d(v);
}

/////////////////////////////////////////////////
/// @brief Get a negative vector2d
///
/// @param[in] v - vector2d
/// @return The negative vector2d of v
/// @relates vector2d
/////////////////////////////////////////////////
vector2d operator-(vector2d const &v)
{
    return vector2d(-v.x, -v.y);
}

/////////////////////////////////////////////////
/// @brief Addition of two vector2d
///
/// @param[in] lhs - first vector2d
/// @param[in] rhs - second vector2d
/// @return The addition of lhs and rhs
/// @relates vector2d
/////////////////////////////////////////////////
vector2d operator+(vector2d const &lhs, vector2d const &rhs)
{
    return vector2d(lhs) += rhs;
}

/////////////////////////////////////////////////
/// @brief Substraction of two vector2d
///
/// @param[in] lhs - first vector2d
/// @param[in] rhs - second vector2d
/// @return The substraction of lhs and rhs
/// @relates vector2d
/////////////////////////////////////////////////
vector2d operator-(vector2d const &lhs, vector2d const &rhs)
{
    return vector2d(lhs) -= rhs;
}

/////////////////////////////////////////////////
/// @brief Multiplication of a vector2d by a scalar
///
/// @param[in] lhs - vector2d
/// @param[in] scalar - scalar value
/// @return The multiplication of lhs by scalar
/// @relates vector2d
/////////////////////////////////////////////////
vector2d operator*(vector2d const &lhs, float scalar)
{
    return vector2d(lhs) *= scalar;
}

/////////////////////////////////////////////////
/// @brief Multiplication of a vector2d by a scalar
///
/// @param[in] scalar - scalar value
/// @param[in] rhs - vector2d
/// @return The multiplication of rhs by scalar
/// @relates vector2d
/////////////////////////////////////////////////
vector2d operator*(float scalar, vector2d const &rhs)
{
    return vector2d(rhs) *= scalar;
}

/////////////////////////////////////////////////
/// @brief Equality operator
///
/// @param[in] lhs - first vector2d
/// @param[in] rhs - second vector2d
/// @return true if lhs is equal to rhs
/// @relates vector2d
/////////////////////////////////////////////////
bool operator==(const vector2d &lhs, const vector2d &rhs)
{
    return equal(lhs.x, rhs.x) and equal(lhs.y, rhs.y);
}

/////////////////////////////////////////////////
/// @brief Not equal operator
///
/// @param[in] lhs - first vector2d
/// @param[in] rhs - second vector2d
/// @return true if lhs is not equal to rhs
/// @relates vector2d
/////////////////////////////////////////////////
bool operator!=(const vector2d &lhs, const vector2d &rhs)
{
    return !(lhs == rhs);
}
} // namespace onii

#endif // ONII_VECTOR2D_HPP
