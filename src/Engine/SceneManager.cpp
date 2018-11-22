#include <Engine/SceneManager.hpp>

namespace Engine
{
    void SceneManager::pushScene(ScenePtr scene, bool makeCurrent)
    {
        if (!m_Scenes.empty()) {
            if (makeCurrent)
                m_Scenes.pop();
            else
                m_Scenes.top()->pause();
        }

        m_Scenes.push(std::move(scene));
        m_Scenes.top()->initialize();
#ifdef DEBUG
        spdlog::get("console")->info("Pushed scene.");
#endif
    }

    void SceneManager::popScene()
    {
        if (!m_Scenes.empty()) {
            m_Scenes.pop();

            if (!m_Scenes.empty()) m_Scenes.top()->resume();
        }
#ifdef DEBUG
        spdlog::get("console")->info("Poped scene.");
#endif
    }

    ScenePtr& SceneManager::getActiveScene() { return m_Scenes.top(); }
} // namespace Engine
