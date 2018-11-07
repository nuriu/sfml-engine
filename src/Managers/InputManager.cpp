#include <Managers/InputManager.hpp>

bool InputManager::isKeyPressed(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& window)
{
    return sf::Mouse::getPosition(window);
}
