#ifndef ONII_PERCENTAGE_HPP
#define ONII_PERCENTAGE_HPP

/////////////////////////////////////////////////
/// @file onii/percentage.hpp
/////////////////////////////////////////////////

#include "float/equal.hpp"

///////////////////////////////////////////////////////////
/// @namespace onii
///////////////////////////////////////////////////////////
namespace onii
{
///////////////////////////////////////////////////////////
/// @class percentage
/// @brief Class representing a percentage
///
/// Allow to write code like this:
/// @code
/// float Price = 200;
/// Price -= onii::percentage(10);      // Apply a sale
/// std::cout << Price << std::endl;    // Print "180"
/// @endcode
///////////////////////////////////////////////////////////
class percentage
{
    public:

        ///////////////////////////////////////////////////
        /// @brief Constructor
        /// @param[in] percent - The percentage value
        ///////////////////////////////////////////////////
        percentage(float percent) :
            m_percent(percent / 100.f)
        {}

        ///////////////////////////////////////////////////
        /// @brief Affection operator
        /// @param[in] percent - The percentage value
        /// @return *this
        ///////////////////////////////////////////////////
        percentage &operator=(float percent)
        {
            m_percent = percent / 100.f;
            return *this;
        }

        ///////////////////////////////////////////////////
        /// @brief Get the percentage divised by 100
        /// @return value() / 100.f
        ///////////////////////////////////////////////////
        float real(void) const
        {
            return m_percent;
        }

        ///////////////////////////////////////////////////
        /// @brief Get the percentage
        /// @return The percentage
        ///////////////////////////////////////////////////
        float value(void) const
        {
            return m_percent * 100.f;
        }

        ///////////////////////////////////////////////////
        /// @brief Multiplication by percent
        /// @param[in] rhs : Factor
        /// @return *this
        ///////////////////////////////////////////////////
        percentage &operator*=(percentage const &rhs)
        {
            m_percent *= rhs.real();
            return *this;
        }

        ///////////////////////////////////////////////////
        /// @brief Division by percent
        /// @param[in] rhs : Divisor
        /// @return *this
        ///////////////////////////////////////////////////
        percentage &operator/=(percentage const &rhs)
        {
            m_percent /= rhs.real();
            return *this;
        }

        ///////////////////////////////////////////////////
        /// @brief Addition with percent
        /// @param[in] rhs : Term
        /// @return *this
        ///////////////////////////////////////////////////
        percentage &operator+=(percentage const &rhs)
        {
            m_percent += rhs.real();
            return *this;
        }

        ///////////////////////////////////////////////////
        /// @brief Subtraction with percent
        /// @param[in] rhs : Term
        /// @return *this
        ///////////////////////////////////////////////////
        percentage &operator-=(percentage const &rhs)
        {
            m_percent -= rhs.real();
            return *this;
        }

    private:

        /* Data member */
        float m_percent;
};

///////////////////////////////////////////////////////////
/// @brief Unary +
/// @param[in] instance : A percentage
/// @return instance
/// @relates percentage
///////////////////////////////////////////////////////////
percentage operator+(percentage const &instance)
{
    return percentage(instance);
}

///////////////////////////////////////////////////////////
/// @brief Unary -
/// @param[in] instance : A percentage
/// @return The negative percentage
/// @relates percentage
///////////////////////////////////////////////////////////
percentage operator-(percentage const &instance)
{
    return percentage(-instance.value());
}

///////////////////////////////////////////////////////////
/// @brief Multiplication
/// @param[in] lhs : Factor
/// @param[in] rhs : Factor
/// @return percentage(lhs) *= rhs
/// @relates percentage
///////////////////////////////////////////////////////////
percentage operator*(percentage const &lhs, percentage const &rhs)
{
    return percentage(lhs) *= rhs;
}

///////////////////////////////////////////////////////////
/// @brief Division
/// @param[in] lhs : Dividend
/// @param[in] rhs : Divisor
/// @return percentage(lhs) /= rhs
/// @relates percentage
///////////////////////////////////////////////////////////
percentage operator/(percentage const &lhs, percentage const &rhs)
{
    return percentage(lhs) /= rhs;
}

///////////////////////////////////////////////////////////
/// @brief Addition
/// @param[in] lhs : Term
/// @param[in] rhs : Term
/// @return percentage(lhs) += rhs
/// @relates percentage
///////////////////////////////////////////////////////////
percentage operator+(percentage const &lhs, percentage const &rhs)
{
    return percentage(lhs) += rhs;
}

///////////////////////////////////////////////////////////
/// @brief Subtraction
/// @param[in] lhs : Term
/// @param[in] rhs : Term
/// @return percentage(lhs) -= rhs
/// @relates percentage
///////////////////////////////////////////////////////////
percentage operator-(percentage const &lhs, percentage const &rhs)
{
    return percentage(lhs) -= rhs;
}

///////////////////////////////////////////////////////////
/// @brief Part of a num
/// @param[in] lhs : num
/// @param[in] rhs : percentage
/// @return lhs * rhs.real()
/// @relates percentage
///////////////////////////////////////////////////////////
float operator*(float lhs, percentage const &rhs)
{
    return lhs * rhs.real();
}

///////////////////////////////////////////////////////////
/// @brief Inverse part of a num
/// @param[in] lhs : num
/// @param[in] rhs : percentage
/// @return lhs / rhs.real()
/// @relates percentage
///////////////////////////////////////////////////////////
float operator/(float lhs, percentage const &rhs)
{
    return lhs / rhs.real();
}

///////////////////////////////////////////////////////////
/// @brief Increase of a num
/// @param[in] lhs : num
/// @param[in] rhs : percentage
/// @return lhs * (1. + rhs.real())
/// @relates percentage
///////////////////////////////////////////////////////////
float operator+(float lhs, percentage const &rhs)
{
    return lhs * (1. + rhs.real());
}

///////////////////////////////////////////////////////////
/// @brief Decrease of a num
/// @param[in] lhs : num
/// @param[in] rhs : percentage
/// @return lhs * (1. - rhs.real())
/// @relates percentage
///////////////////////////////////////////////////////////
float operator-(float lhs, percentage const &rhs)
{
    return lhs * (1. - rhs.real());
}

///////////////////////////////////////////////////////////
/// @brief Part of a num
/// @param[in, out] lhs : num
/// @param[in] rhs : percentage
/// @return lhs = lhs * rhs
/// @relates percentage
///////////////////////////////////////////////////////////
float &operator*=(float &lhs, percentage const &rhs)
{
    return lhs = lhs * rhs;
}

///////////////////////////////////////////////////////////
/// @brief Inverse part of a num
/// @param[in, out] lhs : num
/// @param[in] rhs : percentage
/// @return lhs = lhs / rhs
/// @relates percentage
///////////////////////////////////////////////////////////
float &operator/=(float &lhs, percentage const &rhs)
{
    return lhs = lhs / rhs;
}

///////////////////////////////////////////////////////////
/// @brief Increase of a num
/// @param[in, out] lhs : num
/// @param[in] rhs : percentage
/// @return lhs = lhs + rhs
/// @relates percentage
///////////////////////////////////////////////////////////
float &operator+=(float &lhs, percentage const &rhs)
{
    return lhs = lhs + rhs;
}

///////////////////////////////////////////////////////////
/// @brief Decrease of a num
/// @param[in, out] lhs : num
/// @param[in] rhs : percentage
/// @return lhs = lhs - rhs
/// @relates percentage
///////////////////////////////////////////////////////////
float &operator-=(float &lhs, percentage const &rhs)
{
    return lhs = lhs - rhs;
}

///////////////////////////////////////////////////////////
/// @brief Comparaison operator
/// @param[in] lhs : Left percentage
/// @param[in] rhs : Right percentage
/// @return lhs.real() == rhs.real()
/// @relates percentage
///////////////////////////////////////////////////////////
bool operator==(percentage const &lhs, percentage const &rhs)
{
    return equal(lhs.real(), rhs.real());
}

///////////////////////////////////////////////////////////
/// @brief Comparaison operator
/// @param[in] lhs : Left percentage
/// @param[in] rhs : Right percentage
/// @return !(lhs == rhs)
/// @relates percentage
///////////////////////////////////////////////////////////
bool operator!=(percentage const &lhs, percentage const &rhs)
{
    return !(lhs == rhs);
}

///////////////////////////////////////////////////////////
/// @brief Comparaison operator
/// @param[in] lhs : Left percentage
/// @param[in] rhs : Right percentage
/// @return lhs.real() < rhs.real()
/// @relates percentage
///////////////////////////////////////////////////////////
bool operator<(percentage const &lhs, percentage const &rhs)
{
    return lhs.real() < rhs.real();
}

///////////////////////////////////////////////////////////
/// @brief Comparaison operator
/// @param[in] lhs : Left percentage
/// @param[in] rhs : Right percentage
/// @return rhs < lhs
/// @relates percentage
///////////////////////////////////////////////////////////
bool operator>(percentage const &lhs, percentage const &rhs)
{
    return rhs < lhs;
}

///////////////////////////////////////////////////////////
/// @brief Comparaison operator
/// @param[in] lhs : Left percentage
/// @param[in] rhs : Right percentage
/// @return !(rhs < lhs)
/// @relates percentage
///////////////////////////////////////////////////////////
bool operator<=(percentage const &lhs, percentage const &rhs)
{
    return !(rhs < lhs);
}

///////////////////////////////////////////////////////////
/// @brief Comparaison operator
/// @param[in] lhs : Left percentage
/// @param[in] rhs : Right percentage
/// @return !(lhs < rhs)
/// @relates percentage
///////////////////////////////////////////////////////////
bool operator>=(percentage const &lhs, percentage const &rhs)
{
    return !(lhs < rhs);
}
}

#endif // ONII_PERCENTAGE_HPP
