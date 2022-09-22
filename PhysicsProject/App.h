#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class App
{
public:
    static sf::RenderWindow* GetWindow() { return m_window; }
    static void SetWindow(sf::RenderWindow& window) { m_window = &window; }
private:
    inline static sf::RenderWindow* m_window;
};
