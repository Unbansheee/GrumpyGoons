#include "TimedCallback.h"

#include "Log.h"

TimedCallback::TimedCallback()
{
}

TimedCallback::TimedCallback(std::function<void()> callback, float seconds)
{
    Begin(callback, seconds);
}

void TimedCallback::Begin(std::function<void()> callback, float seconds)
{
    m_Callback = callback;
    m_Delay = seconds;
    
    m_Task = std::async(std::launch::async, &TimedCallback::AsyncTask, this);
}

void TimedCallback::AsyncTask()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(int(m_Delay * 1000)));
    m_Callback();
}
