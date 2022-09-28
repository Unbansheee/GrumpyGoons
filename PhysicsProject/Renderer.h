#pragma once
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>


class Renderer
{
public:
    static void Submit(sf::Drawable& drawable, int priority = 0);
    static void Submit(sf::Text text, int priority = 0);
    static void Flush();

    static inline sf::RenderWindow* m_window;
    static void SetViewport(sf::View& view);
    static sf::Vector2u GetWindowSize();
private:
    static inline std::vector<std::pair<sf::Drawable*, int>> m_drawables;
    static inline std::vector<std::pair<sf::Text, int>> m_texts;
    static inline sf::Vector2i m_viewportSize;
    static inline sf::View* m_activeView;
    
};
 