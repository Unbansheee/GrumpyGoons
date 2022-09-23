#pragma once
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <array>

class Input
{
public:
    // Returns the distance of the mouse wheel since the last frame. -1 to 1 space
    static float GetMouseScrollDelta();

    // Get the current status of a key
    static bool IsKeyDown(sf::Keyboard::Key key);

    // Get the current status of a mouse button
    static bool IsMouseButtonDown(sf::Mouse::Button button);

    // Check if a key was pressed this frame
    static bool WasKeyPressed(sf::Keyboard::Key key);

    // Check if a key was released this frame
    static bool WasKeyReleased(sf::Keyboard::Key key);

    // Check if a mouse button was pressed this frame
    static bool WasMouseButtonPressed(sf::Mouse::Button button);

    // Check if a mouse button was released this frame
    static bool WasMouseButtonReleased(sf::Mouse::Button button);

    // Get the current position of the mouse
    static sf::Vector2i GetMousePosition();

    static sf::Vector2f GetMouseMoveDelta();
    
    static void ProcessEvent(const sf::Event& _event);
    static void Reset();
private:
    friend class Application;


    
    inline static float m_mouseScrollDelta = 0.f;
    
    // Key states
    inline static std::array<bool, sf::Keyboard::KeyCount> m_keyPressed = { false };
    inline static std::array<bool, sf::Keyboard::KeyCount> m_keyReleased = { false };

    // Mouse states
    inline static std::array<bool, sf::Mouse::ButtonCount> m_mouseButtonPressed = { false };
    inline static std::array<bool, sf::Mouse::ButtonCount> m_mouseButtonReleased = { false };
    inline static sf::Vector2f m_mouseMoveDelta = { 0.f, 0.f };
    inline static sf::Vector2i m_previousMousePosition = { 0, 0 };
    
};
    
