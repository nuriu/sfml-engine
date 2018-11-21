#ifndef ENGINE_INPUT_MANAGER_HPP
#define ENGINE_INPUT_MANAGER_HPP
#pragma once

#ifndef D
#define D(x) x
#endif

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <spdlog/spdlog.h>

#include <memory>

namespace Engine
{
    class InputManager
    {
      public:
        std::unique_ptr<sf::Event> m_Event;

        InputManager();

        bool         isKeyPressed(sf::Keyboard::Key key);
        sf::Vector2i getMousePosition(sf::RenderWindow& window);
    };
} // namespace Engine

#endif // ENGINE_INPUT_MANAGER_HPP
