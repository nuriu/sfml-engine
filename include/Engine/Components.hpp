#ifndef ENGINE_COMPONENTS_HPP
#define ENGINE_COMPONENTS_HPP
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include <Engine/SceneManager.hpp>
#include <Engine/InputManager.hpp>
#include <Engine/AssetManager.hpp>

#include <memory>

namespace Engine
{
    struct Components {
        std::unique_ptr<sf::RenderWindow> m_RenderWindow;

        std::unique_ptr<SceneManager> m_SceneManager = std::make_unique<SceneManager>();
        std::unique_ptr<InputManager> m_InputManager = std::make_unique<InputManager>();
        std::unique_ptr<AssetManager> m_AssetManager = std::make_unique<AssetManager>();

        std::unique_ptr<sf::Time> m_DeltaTime = std::make_unique<sf::Time>();
    };
} // namespace Engine

#endif // ENGINE_COMPONENTS_HPP
