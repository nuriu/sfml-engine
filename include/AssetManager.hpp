#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP
#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <string>
#include <map>

class AssetManager
{
  public:
    void loadFont(const std::string& name, const std::string& path);
    void loadTexture(const std::string& name, const std::string& path);

    sf::Font& getFont(const std::string& name);
    sf::Texture& getTexture(const std::string& name);

  private:
    std::map<std::string, sf::Font> m_Fonts;
    std::map<std::string, sf::Texture> m_Textures;
};

#endif // ASSET_MANAGER_HPP
