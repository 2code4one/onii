#ifndef ONII_TIMER_HPP
#define ONII_TIMER_HPP

/////////////////////////////////////////////////
/// @file onii/timer.hpp
/////////////////////////////////////////////////

#include <chrono>
#include "unit/time.hpp"

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @class timer
/// @brief Time chronometer
/////////////////////////////////////////////////
class timer
{
public:

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in] start_timer - if true, onii::timer::start() is called
    /////////////////////////////////////////////////
    timer(bool start_timer = false) :
        m_running(false),
        m_start(),
        m_end()
    {
        if(start_timer)
            start();
    }

    /////////////////////////////////////////////////
    /// @brief Destructor
    /////////////////////////////////////////////////
    virtual ~timer()
    {}

    /////////////////////////////////////////////////
    /// @brief Start the chronometer
    /////////////////////////////////////////////////
    void start()
    {
        if(!m_running)
        {
            m_start = std::chrono::high_resolution_clock::now();
            m_running = true;
        }
    }

    /////////////////////////////////////////////////
    /// @brief Restart the chronometer
    /////////////////////////////////////////////////
    void restart()
    {
        m_start = std::chrono::high_resolution_clock::now();
        m_running = true;
    }

    /////////////////////////////////////////////////
    /// @brief Stop the chonometer
    /////////////////////////////////////////////////
    void stop()
    {
        if(m_running)
        {
            m_end = std::chrono::high_resolution_clock::now();
            m_running = false;
        }
    }

    /////////////////////////////////////////////////
    /// @brief Return the elapsed time
    ///
    /// @return Time elapsed
    /////////////////////////////////////////////////
    unit::time elapsed() const
    {
        return unit::time::s(
            std::chrono::duration_cast<std::chrono::duration<unit::time::time_type>>(
                (m_running ? std::chrono::high_resolution_clock::now() : m_end) - m_start
            ).count()
        );
    }

private:

    bool m_running;
    std::chrono::high_resolution_clock::time_point m_start;
    std::chrono::high_resolution_clock::time_point m_end;
};

/////////////////////////////////////////////////
/// @class scoped_timer
/// @brief Scoped time chronometer
/////////////////////////////////////////////////
class scoped_timer :
    private timer
{
public:

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[out] time - reference to a unit::time object
    /////////////////////////////////////////////////
    scoped_timer(unit::time &time) :
        timer(true),
        m_time(time)
    {}

    /////////////////////////////////////////////////
    /// @brief Destructor
    ///
    /// Set the time parameter of the constructor to the elapsed time between the object construction/destruction
    /////////////////////////////////////////////////
    ~scoped_timer()
    {
        m_time = elapsed();
    }

private:

    unit::time &m_time;
};

/////////////////////////////////////////////////
/// @class global_timer
/// @brief Program global time chronometer
/////////////////////////////////////////////////
class global_timer
{
public:

    /////////////////////////////////////////////////
    /// @brief Return the time elapsed since the program begin
    ///
    /// @return Time elapsed since the program begin
    /////////////////////////////////////////////////
    static unit::time elapsed()
    {
        return m_timer.elapsed();
    }

private:

    static timer m_timer;
};

timer global_timer::m_timer = timer(true);
}

#endif // ONII_TIMER_HPP
