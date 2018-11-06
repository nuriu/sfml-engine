#include <AssetManager.hpp>

void AssetManager::loadFont(const std::string& name, const std::string& path)
{
    auto font = std::make_unique<sf::Font>();

    if (font->loadFromFile(path))
    {
        m_Fonts[name] = *font;
    }
}

void AssetManager::loadSound(const std::string& name, const std::string& path)
{
    auto buffer = std::make_unique<sf::SoundBuffer>();

    if (buffer->loadFromFile(path))
    {
        m_SoundBuffers[name] = *buffer;
        m_Sounds[name] = sf::Sound(m_SoundBuffers[name]);
    }
}

void AssetManager::loadTexture(const std::string& name, const std::string& path)
{
    auto texture = std::make_unique<sf::Texture>();

    if (texture->loadFromFile(path))
    {
        m_Textures[name] = *texture;
    }
}

void AssetManager::playSound(const std::string& name)
{
    m_Sounds[name].play();
}

void AssetManager::pauseSound(const std::string& name)
{
    m_Sounds[name].pause();
}

void AssetManager::stopSound(const std::string& name)
{
    m_Sounds[name].stop();
}

sf::Font& AssetManager::getFont(const std::string& name)
{
    return m_Fonts.at(name);
}

sf::Texture& AssetManager::getTexture(const std::string& name)
{
    return m_Textures.at(name);
}
