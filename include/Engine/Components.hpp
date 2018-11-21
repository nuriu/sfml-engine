#ifndef ENGINE_COMPONENTS_HPP
#define ENGINE_COMPONENTS_HPP
#pragma once

#ifdef DEBUG
#define D(x) x
#else
#define D(x)
#endif

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <Engine/SceneManager.hpp>
#include <Engine/InputManager.hpp>
#include <Engine/AssetManager.hpp>

#include <memory>

namespace Engine
{
    struct Components {
        D(std::shared_ptr<spdlog::logger> m_Logger = spdlog::stdout_color_mt("console");)

        std::unique_ptr<sf::RenderWindow> m_RenderWindow;
        std::unique_ptr<SceneManager>     m_SceneManager = std::make_unique<SceneManager>();
        std::unique_ptr<InputManager>     m_InputManager = std::make_unique<InputManager>();
        std::unique_ptr<AssetManager>     m_AssetManager = std::make_unique<AssetManager>();
        std::unique_ptr<sf::Time>         m_DeltaTime    = std::make_unique<sf::Time>();
    };
} // namespace Engine

#endif // ENGINE_COMPONENTS_HPP
