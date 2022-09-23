#pragma once
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Renderer
{
public:
    static void Submit(sf::Drawable& drawable, int priority = 0);
    static void Flush();

    static inline sf::RenderWindow* m_window;
    static void SetViewport(sf::View& view);
    static sf::Vector2u GetWindowSize();
private:
    static inline std::vector<std::pair<sf::Drawable*, int>> m_drawables;
    static inline sf::Vector2i m_viewportSize;
    static inline sf::View* m_activeView;
    
};
 