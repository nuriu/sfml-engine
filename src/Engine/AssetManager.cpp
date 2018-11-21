#include <Engine/AssetManager.hpp>

namespace Engine
{
    void AssetManager::loadFont(const std::string& name, const std::string& path)
    {
        auto font = std::make_unique<sf::Font>();

        if (font->loadFromFile(path)) {
            m_Fonts[name] = *font;
            D(spdlog::get("console")->info("Loaded font named {} from {}.", name, path);)
        } else {
            D(spdlog::get("console")->error("Couldn't load font named {} from {}.", name, path);)
        }
    }

    void AssetManager::loadSound(const std::string& name, const std::string& path)
    {
        auto buffer = std::make_unique<sf::SoundBuffer>();

        if (buffer->loadFromFile(path)) {
            m_SoundBuffers[name] = *buffer;
            m_Sounds[name]       = sf::Sound(m_SoundBuffers[name]);
            D(spdlog::get("console")->info("Loaded sound named {} from {}.", name, path);)
        } else {
            D(spdlog::get("console")->error("Couldn't load sound named {} from {}.", name, path);)
        }
    }

    void AssetManager::loadTexture(const std::string& name, const std::string& path)
    {
        auto texture = std::make_unique<sf::Texture>();

        if (texture->loadFromFile(path)) {
            m_Textures[name] = *texture;
            D(spdlog::get("console")->info("Loaded texture named {} from {}.", name, path);)
        } else {
            D(spdlog::get("console")->error("Couldn't load texture named {} from {}.", name, path);)
        }
    }

    void AssetManager::playSound(const std::string& name) { m_Sounds[name].play(); }

    void AssetManager::pauseSound(const std::string& name) { m_Sounds[name].pause(); }

    void AssetManager::stopSound(const std::string& name) { m_Sounds[name].stop(); }

    sf::Font& AssetManager::getFont(const std::string& name) { return m_Fonts.at(name); }

    sf::Texture& AssetManager::getTexture(const std::string& name) { return m_Textures.at(name); }
} // namespace Engine
