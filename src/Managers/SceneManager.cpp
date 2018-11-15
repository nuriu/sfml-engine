#include <Managers/SceneManager.hpp>

void SceneManager::pushScene(ScenePtr scene, bool makeCurrent)
{
    if (!m_Scenes.empty())
    {
        if (makeCurrent)
        {
            m_Scenes.pop();
        }
        else
        {
            m_Scenes.top()->pause();
        }
    }

    m_Scenes.push(std::move(scene));
    m_Scenes.top()->initialize();
}

void SceneManager::popScene()
{
    if (!m_Scenes.empty())
    {
        m_Scenes.pop();

        if (!m_Scenes.empty())
        {
            m_Scenes.top()->resume();
        }
    }
}

ScenePtr& SceneManager::getActiveScene() { return m_Scenes.top(); }
