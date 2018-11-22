#ifndef GAME_GAME_SCENE_HPP
#define GAME_GAME_SCENE_HPP
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

#include <Engine/Scene.hpp>
#include <Engine/Components.hpp>

#include <memory>
#include <iostream>

class GameScene final : public Engine::Scene
{
  public:
    explicit GameScene(const Engine::Components& components);

    void initialize() override;
    void processInput() override;
    void update() override;
    void render() const override;
    void pause() override;
    void resume() override;

  private:
    const Engine::Components&        m_Components;
    std::unique_ptr<sf::CircleShape> m_Shape;
};

#endif // GAME_GAME_SCENE_HPP
