#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

#include <Scenes/Scene.hpp>
#include <CoreComponents.hpp>

#include <memory>
#include <iostream>

class GameScene : public Scene
{
  public:
    GameScene(const CoreComponents& components);

    void initialize() override;
    void processInput() override;
    void update() override;
    void render() const override;
    void pause() override;
    void resume() override;

  private:
    const CoreComponents& m_Components;
    std::unique_ptr<sf::CircleShape> m_Shape;
};

#endif // GAME_SCENE_HPP
