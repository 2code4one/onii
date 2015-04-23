#ifndef ONII_PHYSIC_VECTOR_HPP
#define ONII_PHYSIC_VECTOR_HPP

/////////////////////////////////////////////////
/// @file onii/physic/vector.hpp
/////////////////////////////////////////////////

#include <cmath>
#include "../float/equal.hpp"

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @namespace onii::physic
/////////////////////////////////////////////////
namespace physic
{
/////////////////////////////////////////////////
/// @class vector
/// @brief Class representing a 2D vector
/////////////////////////////////////////////////
class vector
{
public:

    float x; ///< x component
    float y; ///< y component

    /////////////////////////////////////////////////
    /// @brief Default constructor
    /////////////////////////////////////////////////
    vector() :
        x(0.f),
        y(0.f)
    {}

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in] x_ - x component
    /// @param[in] y_ - y component
    /////////////////////////////////////////////////
    vector(float x_, float y_) :
        x(x_),
        y(y_)
    {}

    /////////////////////////////////////////////////
    /// @brief Addition
    ///
    /// @param[in] rhs - The vector to add
    /// @return *this
    /////////////////////////////////////////////////
    vector &operator+=(vector const &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Substraction
    ///
    /// @param[in] rhs - The vector to substract
    /// @return *this
    /////////////////////////////////////////////////
    vector &operator-=(vector const &rhs)
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
    vector &operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    /////////////////////////////////////////////////
    /// @brief Get the squared length
    ///
    /// @param[in] v - vector to compute
    /// @return The squared length value
    /////////////////////////////////////////////////
    static float squared_lenght(vector const &v)
    {
        return v.x * v.x + v.y * v.y;
    }

    /////////////////////////////////////////////////
    /// @brief Get the length
    ///
    /// @param[in] v - vector to compute
    /// @return The length value
    /////////////////////////////////////////////////
    static float lenght(vector const &v)
    {
        return std::sqrt(squared_lenght(v));
    }

    /////////////////////////////////////////////////
    /// @brief Get a normalized vector
    ///
    /// @param[in] v - vector to normalize
    /// @return The normalized vector
    /////////////////////////////////////////////////
    static vector normalize(vector const &v)
    {
        float len = lenght(v);
        return vector(v.x / len, v.y / len);
    }

    /////////////////////////////////////////////////
    /// @brief Compute the dot product of two vectors
    ///
    /// @param[in] lhs - first vector
    /// @param[in] rhs - second vector
    /// @return The computed dot product
    /////////////////////////////////////////////////
    static float dot_product(vector const &lhs, vector const &rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    /////////////////////////////////////////////////
    /// @brief Compute the cross product of two vector
    ///
    /// @param[in] lhs - first vector
    /// @param[in] rhs - second vector
    /// @return The computed cross product
    /// @remarks This function return only the z component value
    ///          of the computed cross product, because this class
    ///          is only a 2D vector
    /////////////////////////////////////////////////
    static float cross_product_z(vector const &lhs, vector const &rhs)
    {
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }

    /////////////////////////////////////////////////
    /// @brief Get the orthogonal vector
    ///
    /// @param[in] v - the vector
    /// @return A orthogonal vector of v
    /// @remarks The orthogonal vector is computed
    ///          like this: @code (v.y -v.x) @endcode
    /////////////////////////////////////////////////
    static vector orthogonal_x(vector const &v)
    {
        return vector(v.y, -v.x);
    }

    /////////////////////////////////////////////////
    /// @brief Get the orthogonal vector
    ///
    /// @param[in] v - the vector
    /// @return A orthogonal vector of v
    /// @remarks The orthogonal vector is computed
    ///          like this: @code (-v.y v.x) @endcode
    /////////////////////////////////////////////////
    static vector orthogonal_y(vector const &v)
    {
        return vector(-v.y, v.x);
    }

    /////////////////////////////////////////////////
    /// @brief Rotate a vector with a given angle
    ///
    /// @param[in] v - vector to rotate
    /// @param[in] angle - the rotation angle
    /// @return the rotated vector
    /// @remarks The rotation is counter-clockwise
    /////////////////////////////////////////////////
    static vector rotate(vector const &v, unit::angle angle)
    {
        float c = std::cos(angle.rad());
        float s = std::sin(angle.rad());
        return vector(v.x * c - v.y * s, v.x * s + v.y * c);
    }

}; // class vector

/////////////////////////////////////////////////
/// @brief Get a positive vector
///
/// @param[in] v - vector
/// @return The same vector as v
/// @relates vector
/////////////////////////////////////////////////
vector operator+(vector const &v)
{
    return vector(v);
}

/////////////////////////////////////////////////
/// @brief Get a negative vector
///
/// @param[in] v - vector
/// @return The negative vector of v
/// @relates vector
/////////////////////////////////////////////////
vector operator-(vector const &v)
{
    return vector(-v.x, -v.y);
}

/////////////////////////////////////////////////
/// @brief Addition of two vector
///
/// @param[in] lhs - first vector
/// @param[in] rhs - second vector
/// @return The addition of lhs and rhs
/// @relates vector
/////////////////////////////////////////////////
vector operator+(vector const &lhs, vector const &rhs)
{
    return vector(lhs) += rhs;
}

/////////////////////////////////////////////////
/// @brief Substraction of two vector
///
/// @param[in] lhs - first vector
/// @param[in] rhs - second vector
/// @return The substraction of lhs and rhs
/// @relates vector
/////////////////////////////////////////////////
vector operator-(vector const &lhs, vector const &rhs)
{
    return vector(lhs) -= rhs;
}

/////////////////////////////////////////////////
/// @brief Multiplication of a vector by a scalar
///
/// @param[in] lhs - vector
/// @param[in] scalar - scalar value
/// @return The multiplication of lhs by scalar
/// @relates vector
/////////////////////////////////////////////////
vector operator*(vector const &lhs, float scalar)
{
    return vector(lhs) *= scalar;
}

/////////////////////////////////////////////////
/// @brief Multiplication of a vector by a scalar
///
/// @param[in] scalar - scalar value
/// @param[in] rhs - vector
/// @return The multiplication of rhs by scalar
/// @relates vector
/////////////////////////////////////////////////
vector operator*(float scalar, vector const &rhs)
{
    return vector(rhs) *= scalar;
}

/////////////////////////////////////////////////
/// @brief Equality operator
///
/// @param[in] lhs - first vector
/// @param[in] rhs - second vector
/// @return true if lhs is equal to rhs
/// @relates vector
/////////////////////////////////////////////////
bool operator==(const vector &lhs, const vector &rhs)
{
    return equal(lhs.x, rhs.x) and equal(lhs.y, rhs.y);
}

/////////////////////////////////////////////////
/// @brief Not equal operator
///
/// @param[in] lhs - first vector
/// @param[in] rhs - second vector
/// @return true if lhs is not equal to rhs
/// @relates vector
/////////////////////////////////////////////////
bool operator!=(const vector &lhs, const vector &rhs)
{
    return !(lhs == rhs);
}
} // namespace physic
} // namespace onii

#endif // ONII_PHYSIC_VECTOR_HPP
