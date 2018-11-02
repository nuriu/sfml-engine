#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include <Scene.hpp>

#include <memory>

class GameScene : public Scene
{
  public:
    GameScene(sf::RenderWindow* window);

    void initialize() override;
    void processInput() override;
    void update(float deltaTime) override;
    void render() const override;
    void pause() override;
    void resume() override;

  private:
    sf::RenderWindow* m_RenderWindow;

    std::unique_ptr<sf::CircleShape> m_Shape;
};

#endif // GAME_SCENE_HPP
