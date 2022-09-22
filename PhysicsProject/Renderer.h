#pragma once
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Renderer
{
public:
    static void Submit(sf::Drawable& drawable, int priority = 0);
    static void Flush();

    static inline sf::RenderWindow* m_window;
private:
    static inline std::vector<std::pair<sf::Drawable*, int>> m_drawables;
    
    
};
 