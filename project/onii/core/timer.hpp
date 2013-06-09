#ifndef ONII_CORE_TIMER_HPP
#define ONII_CORE_TIMER_HPP

#include <chrono>
#include "../physic/unit/time.hpp"

namespace onii
{
namespace core
{
class timer
{
public:

    timer(bool start_timer = false) :
        m_running(false)
    {
        if(start_timer)
            start();
    }

    void start()
    {
        if(!m_running)
        {
            m_start = std::chrono::high_resolution_clock::now();
            m_running = true;
        }
    }

    void stop()
    {
        if(m_running)
        {
            m_end = std::chrono::high_resolution_clock::now();
            m_running = false;
        }
    }

    physic::unit::time elapsed() const
    {
        return physic::unit::time::s(
            std::chrono::duration_cast<std::chrono::duration<physic::unit::time::time_type>>(
                (m_running ? std::chrono::high_resolution_clock::now() : m_end) - m_start
            ).count()
        );
    }

private:

    bool m_running;
    std::chrono::high_resolution_clock::time_point m_start;
    std::chrono::high_resolution_clock::time_point m_end;
};

class scoped_timer :
    private timer
{
public:

    scoped_timer(physic::unit::time &time) :
        timer(true),
        m_time(time)
    {}

    ~scoped_timer()
    {
        m_time = elapsed();
    }

private:

    physic::unit::time &m_time;
};
}
}

#endif // ONII_CORE_TIMER_HPP
