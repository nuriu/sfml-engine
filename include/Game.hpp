#ifndef GAME_HPP
#define GAME_HPP
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <SceneManager.hpp>
#include <GameScene.hpp>

#include <memory>

class Game
{
  public:
    Game(const sf::String& title, const unsigned int width,
         const unsigned int height);

    void run();

  private:
    std::unique_ptr<SceneManager> m_SceneManager;
    std::unique_ptr<sf::RenderWindow> m_Window;
    std::unique_ptr<sf::Clock> m_Clock;

    float m_DeltaTime;

    void processEvents();
    void update();
    void render();
};

#endif // GAME_HPP
