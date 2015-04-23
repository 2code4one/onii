#ifndef ONII_DETAIL_RANDOM_HPP
#define ONII_DETAIL_RANDOM_HPP

#include <limits>
#include <random>
#include <type_traits>

namespace onii
{
namespace detail
{
namespace random
{
template<typename T>
struct check_type
{
    virtual ~check_type() {} // warning -Weffc++

    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value,
                  "onii.random can only use integral or floating point types");
};

template<typename T>
struct range_value
    : check_type<T>
{
    constexpr static T min = static_cast<T>(0);
    constexpr static T max =
        std::is_floating_point<T>::value ?
            static_cast<T>(1) :
            std::numeric_limits<T>::max();
};

template<typename T>
struct generator
    : check_type<T>
{
    typedef std::mt19937 type;
};

template<typename T>
struct distribution
    : check_type<T>
{
    typedef typename std::conditional<
        std::is_integral<T>::value,
        std::uniform_int_distribution<T>,
        typename std::conditional<
            std::is_floating_point<T>::value,
            std::uniform_real_distribution<T>,
            void
        >::type
    >::type type;
};
}
}
}

#endif // ONII_DETAIL_RANDOM_HPP
