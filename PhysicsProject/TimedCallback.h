#pragma once
#include <future>

//Unsafe. Callback function will be called from another thread for now.
class TimedCallback
{
public:
    TimedCallback();
    TimedCallback(std::function<void()> callback, float seconds);

    void Begin(std::function<void()> callback, float seconds);

    
private:
    float m_Delay = 1.f;
    std::function<void()> m_Callback;
    std::future<void> m_Task;
    void AsyncTask();
};

