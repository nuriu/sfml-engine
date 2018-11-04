#include <AssetManager.hpp>

void AssetManager::loadFont(const std::string& name, const std::string& path)
{
    sf::Font font;

    if (font.loadFromFile(path))
    {
        m_Fonts[name] = font;
    }
}

void AssetManager::loadTexture(const std::string& name, const std::string& path)
{
    sf::Texture texture;

    if (texture.loadFromFile(path))
    {
        m_Textures[name] = texture;
    }
}

sf::Font& AssetManager::getFont(const std::string& name)
{
    return m_Fonts.at(name);
}

sf::Texture& AssetManager::getTexture(const std::string& name)
{
    return m_Textures.at(name);
}
