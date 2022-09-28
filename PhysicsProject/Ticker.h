#pragma once

class Ticker
{
public:
    Ticker(float interval = 1.0f) : m_interval(interval) {}
    
    bool Update(float dt);
    void Pause();
    void Start();
    void Reset();
    
    void SetInterval(float interval);
    float GetInterval() const;
    float GetTime() const;
    void SetTime(float time);
    float GetProgress() const;
    bool IsPaused() const;
    
    operator bool() const { return m_triggered; }
    
private:
    bool m_triggered = false;
    float m_interval;
    float m_time = 0.0f;
    bool m_paused = false;
};
