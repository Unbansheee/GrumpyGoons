#include "Renderer.h"

void Renderer::Submit(sf::Drawable& drawable, int priority)
{
    m_drawables.emplace_back(&drawable, priority);
}

void Renderer::Flush()
{
    std::sort(m_drawables.begin(), m_drawables.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    for (const auto& [drawable, priority] : m_drawables)
    {
        m_window->draw(*drawable);
    }


    m_drawables.clear();
}
