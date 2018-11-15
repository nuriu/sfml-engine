#include <Managers/InputManager.hpp>

InputManager::InputManager() : m_Event(std::make_unique<sf::Event>()) {}

bool InputManager::isKeyPressed(sf::Keyboard::Key key)
{
    if (m_Event->type == sf::Event::KeyPressed)
    {
        return sf::Keyboard::isKeyPressed(key);
    }

    return false;
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& window)
{
    return sf::Mouse::getPosition(window);
}
