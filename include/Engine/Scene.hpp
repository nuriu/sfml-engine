#ifndef ENGINE_SCENE_HPP
#define ENGINE_SCENE_HPP
#pragma once

namespace Engine
{
    class Scene
    {
      public:
        virtual void initialize()   = 0;
        virtual void processInput() = 0;
        virtual void update()       = 0;
        virtual void render() const = 0;
        virtual void pause()        = 0;
        virtual void resume()       = 0;

        virtual ~Scene() = default;
    };
} // namespace Engine

#endif // ENGINE_SCENE_HPP
