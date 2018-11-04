#ifndef GAME_HPP
#define GAME_HPP
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <CoreComponents.hpp>
#include <GameScene.hpp>

#include <memory>

class Game
{
  public:
    Game(const sf::String& title, const unsigned int width,
         const unsigned int height);

    void run();

  private:
    std::shared_ptr<CoreComponents> m_Components;
    std::unique_ptr<sf::Clock> m_Clock;

    void processEvents();
    void update();
    void render();
};

#endif // GAME_HPP
