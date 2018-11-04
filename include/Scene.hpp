#ifndef SCENE_HPP
#define SCENE_HPP
#pragma once

#include <SFML/Window/Event.hpp>

class Scene
{
  public:
    virtual void initialize() = 0;
    virtual void processInput(sf::Event& event) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() const = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;

    virtual ~Scene() { }
};

#endif // SCENE_HPP