#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <memory>

class InputManager
{
  public:
    bool isKeyPressed(sf::Keyboard::Key key);
    sf::Vector2i getMousePosition(sf::RenderWindow& window);
};

#endif // INPUT_MANAGER_HPP
