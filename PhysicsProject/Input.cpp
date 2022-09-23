#include "Input.h"

float Input::GetMouseScrollDelta()
{
    return m_mouseScrollDelta;
}

bool Input::IsKeyDown(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
}

bool Input::IsMouseButtonDown(sf::Mouse::Button button)
{
    return sf::Mouse::isButtonPressed(button);
}

bool Input::WasKeyPressed(sf::Keyboard::Key key)
{
       return m_keyPressed[key];
}

bool Input::WasKeyReleased(sf::Keyboard::Key key)
{
    return m_keyReleased[key];
}

bool Input::WasMouseButtonPressed(sf::Mouse::Button button)
{
    return m_mouseButtonPressed[button];
}

bool Input::WasMouseButtonReleased(sf::Mouse::Button button)
{
    return m_mouseButtonReleased[button];
}

sf::Vector2i Input::GetMousePosition()
{
    return sf::Mouse::getPosition();
}

sf::Vector2f Input::GetMouseMoveDelta()
{
    return m_mouseMoveDelta;
}

void Input::ProcessEvent(const sf::Event& _event)
{

    
    switch (_event.type)
    {
    case sf::Event::KeyPressed:
        m_keyPressed[_event.key.code] = true;
        break;
    case sf::Event::Closed:

        break;
    case sf::Event::Resized:

        break;
    case sf::Event::LostFocus:

        break;
    case sf::Event::GainedFocus:

        break;
    case sf::Event::TextEntered:

        break;
    case sf::Event::KeyReleased:
        m_keyReleased[_event.key.code] = true;
        break;
    case sf::Event::MouseWheelScrolled:
        m_mouseScrollDelta = _event.mouseWheelScroll.delta;
        break;
    case sf::Event::MouseButtonPressed:
        m_mouseButtonPressed[_event.mouseButton.button] = true;
        break;
    case sf::Event::MouseButtonReleased:
        m_mouseButtonReleased[_event.mouseButton.button] = true;
        break;
    case sf::Event::MouseMoved:
        m_mouseMoveDelta = sf::Vector2f{
            static_cast<float>(m_previousMousePosition.x) - GetMousePosition().x,
            static_cast<float>(m_previousMousePosition.y - GetMousePosition().y)
        };
        break;
    case sf::Event::MouseEntered:

        break;
    case sf::Event::MouseLeft:

        break;
    case sf::Event::JoystickButtonPressed:

        break;
    case sf::Event::JoystickButtonReleased:

        break;
    case sf::Event::JoystickMoved:

        break;
    case sf::Event::JoystickConnected:

        break;
    case sf::Event::JoystickDisconnected:

        break;
    case sf::Event::TouchBegan:

        break;
    case sf::Event::TouchMoved:

        break;
    case sf::Event::TouchEnded:

        break;
    case sf::Event::SensorChanged:

        break;
    case sf::Event::Count:

        break;
    default:
        break;
    
    }
    
}

void Input::Reset()
{
    m_keyPressed.fill(false);
    m_keyReleased.fill(false);
    m_mouseButtonPressed.fill(false);
    m_mouseButtonReleased.fill(false);
    m_mouseScrollDelta = 0;
    m_mouseMoveDelta = sf::Vector2f(0, 0);
    m_previousMousePosition = sf::Mouse::getPosition();
}

