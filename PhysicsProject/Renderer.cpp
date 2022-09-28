#include "Renderer.h"

#include <SFML/Graphics/Text.hpp>

void Renderer::Submit(sf::Drawable& drawable, int priority)
{
    m_drawables.emplace_back(&drawable, priority);
}

void Renderer::Submit(sf::Text text, int priority)
{
    m_texts.emplace_back(text, priority);
}

void Renderer::Flush()
{
    std::sort(m_drawables.begin(), m_drawables.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    if (m_activeView) m_window->setView(*m_activeView);
    else m_window->setView(m_window->getDefaultView());
    
    for (const auto& [drawable, priority] : m_drawables)
    {
        m_window->draw(*drawable);
    }
    
    m_window->setView(m_window->getDefaultView());
    for (auto [text, priority] : m_texts)
    {
        m_window->draw(text);
    }

    if (m_activeView) m_window->setView(*m_activeView);
    
    m_texts.clear();
    m_drawables.clear();
}

void Renderer::SetViewport(sf::View& view)
{
    m_activeView = &view;
}

sf::Vector2u Renderer::GetWindowSize()
{
    return m_window->getSize();
}
