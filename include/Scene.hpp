#ifndef SCENE_HPP
#define SCENE_HPP
#pragma once

class Scene
{
  public:
    virtual void initialize() = 0;
    virtual void processInput() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() const = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;

    virtual ~Scene() { }
};

#endif // SCENE_HPP
