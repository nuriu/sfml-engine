#ifndef CORE_COMPONENTS_HPP
#define CORE_COMPONENTS_HPP
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <Managers/SceneManager.hpp>
#include <Managers/InputManager.hpp>
#include <Managers/AssetManager.hpp>

#include <memory>

struct CoreComponents
{
    std::unique_ptr<SceneManager> m_SceneManager = std::make_unique<SceneManager>();
    std::unique_ptr<InputManager> m_InputManager = std::make_unique<InputManager>();
    std::unique_ptr<AssetManager> m_AssetManager = std::make_unique<AssetManager>();

    std::unique_ptr<sf::RenderWindow> m_RenderWindow;
    std::unique_ptr<sf::Event> m_Event = std::make_unique<sf::Event>();

    float m_DeltaTime = 0.f;
};

#endif // CORE_COMPONENTS_HPP
