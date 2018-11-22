#ifndef ENGINE_GAME_HPP
#define ENGINE_GAME_HPP
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <imgui.h>
#include <imgui-SFML.h>

#include <Engine/Components.hpp>

#include <memory>

namespace Engine
{
    class Application final
    {
      public:
        Application(const sf::String& title, unsigned int width, unsigned int height, const bool fullscreen = false);

        template<typename T> void run()
        {
            m_Components->m_RenderWindow->setVerticalSyncEnabled(true);
            m_Components->m_RenderWindow->setFramerateLimit(60);

            ImGui::SFML::Init(*m_Components->m_RenderWindow);

            m_Components->m_SceneManager->pushScene(ScenePtr(std::make_unique<T>(*m_Components)), true);

            while (m_Components->m_RenderWindow->isOpen()) {
                processEvents();
                update();
                render();
            }
        }

      private:
        std::shared_ptr<Components> m_Components;
        std::unique_ptr<sf::Clock>  m_Clock;

        void processEvents();
        void update();
        void render();
    };
} // namespace Engine

#endif // ENGINE_GAME_HPP
