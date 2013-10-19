#ifndef ONII_LOG_HPP
#define ONII_LOG_HPP

/////////////////////////////////////////////////
/// @file onii/log.hpp
/////////////////////////////////////////////////

#include "detail/log/containers_output.hpp"
#include "detail/log/logger.hpp"

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @namespace onii::log
/////////////////////////////////////////////////
namespace log
{
/////////////////////////////////////////////////
/// @brief Format a container into a std::string
///
/// @pre ContainerT must be functional with std::begin() and std::end()
/// @pre The value type into the container must be outputable into a standard stream
/// @param c - the container
/// @return Container's values formatted into a std::string
/////////////////////////////////////////////////
template<typename ContainerT>
inline std::string container(ContainerT const &c)
{
    return detail::log::containers_output::format_iterator(
        std::begin(c),
        std::end(c)
    );
}

/////////////////////////////////////////////////
/// @cond IGNORE
ONII_DETAIL_LOG_DEFINE_LEVEL(0, debug);
ONII_DETAIL_LOG_DEFINE_LEVEL(1, info);
ONII_DETAIL_LOG_DEFINE_LEVEL(2, warning);
ONII_DETAIL_LOG_DEFINE_LEVEL(3, error);
ONII_DETAIL_LOG_DEFINE_LEVEL(4, fatal);
/// @endcond
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @class onii::log::debug
/// @brief Log level for debugging
/// @remarks thread-safe logging
///
/// Use the debug stream like this:
/// @code
/// onii::log::debug() << "var = " << var;
/// @endcode
/// @remarks std::endl is automatically called
///
/// To add an optionnal tag or to indent the message:
/// @code
/// onii::log::debug("tag") << __LINE__;
/// onii::log::debug("tag", 1) << buffer;
/// onii::log::debug(1) << onii::log::container(list);
/// @endcode
///
/// Enable/Disable the logging output:
/// @code
/// onii::log::debug::active(true); // enable
/// onii::log::debug::active(false); // disable
/// onii::log::debug::active(); // get the current status
/// @endcode
/// @remarks At the program start the output is enabled
///
/// You can redirect the stream:
/// @code
/// std::ostream &old = onii::log::debug::stream();
/// std::ofstream ofs("debug.log");
/// onii::log::debug::redirect(ofs);
/// @endcode
/// @remarks std::cerr is the default stream
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @class onii::log::info
/// @brief Log level for informations
/// @remarks Work the same as onii::log::debug
/// @see onii::log::debug
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @class onii::log::warning
/// @brief Log level for warning messages
/// @remarks Work the same as onii::log::debug
/// @see onii::log::debug
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @class onii::log::error
/// @brief Log level for errors
/// @remarks Work the same as onii::log::debug
/// @see onii::log::debug
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @class onii::log::fatal
/// @brief Log level for fatal errors
/// @remarks Work the same as onii::log::debug
/// @see onii::log::debug
/////////////////////////////////////////////////
}
}

#endif // ONII_LOG_HPP
