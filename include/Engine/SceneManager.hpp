#ifndef ENGINE_SCENE_MANAGER_HPP
#define ENGINE_SCENE_MANAGER_HPP
#pragma once

#include <Engine/Scene.hpp>

#include <spdlog/spdlog.h>

#include <memory>
#include <stack>

namespace Engine
{
    using ScenePtr = std::unique_ptr<Scene>;

    class SceneManager final
    {
      public:
        void      pushScene(ScenePtr scene, bool makeCurrent);
        void      popScene();
        ScenePtr& getActiveScene();

      private:
        std::stack<ScenePtr> m_Scenes;
    };
} // namespace Engine

#endif // ENGINE_SCENE_MANAGER_HPP
