#include "Ticker.h"

bool Ticker::Update(float dt)
{
    
    if (m_paused)
        return false;

    m_time += dt;
    if (m_time >= m_interval)
    {
        m_triggered = true;
        m_time = 0.0f;
        return true;
    }
    m_triggered = false;
    return false;
    
}

void Ticker::Pause()
{
    m_paused = true;
}

void Ticker::Start()
{
    m_paused = false;
}

void Ticker::Reset()
{
    m_triggered = false;
    m_time = 0.0f;
}

void Ticker::SetInterval(float interval)
{
    m_interval = interval;
}

float Ticker::GetInterval() const
{
    return m_interval;
}

float Ticker::GetTime() const
{
    return m_time;
}

void Ticker::SetTime(float time)
{
    m_time = time;
}

float Ticker::GetProgress() const
{
    return m_time / m_interval;
}

bool Ticker::IsPaused() const
{
    return m_paused;
}
