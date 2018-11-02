#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP
#pragma once

#include <Scene.hpp>

#include <memory>
#include <stack>

using ScenePtr = std::unique_ptr<Scene>;

class SceneManager
{
  public:
    void pushScene(ScenePtr scene, bool makeCurrent);
    void popScene();

    ScenePtr& getActiveScene();

  private:
    std::stack<ScenePtr> m_Scenes;
};

#endif // SCENE_MANAGER_HPP
