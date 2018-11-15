#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP
#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <string>
#include <memory>
#include <map>

class AssetManager
{
  public:
    void loadFont(const std::string& name, const std::string& path);
    void loadSound(const std::string& name, const std::string& path);
    void loadTexture(const std::string& name, const std::string& path);

    void playSound(const std::string& name);
    void pauseSound(const std::string& name);
    void stopSound(const std::string& name);

    sf::Font&    getFont(const std::string& name);
    sf::Texture& getTexture(const std::string& name);

  private:
    std::map<std::string, sf::Font>        m_Fonts;
    std::map<std::string, sf::Sound>       m_Sounds;
    std::map<std::string, sf::Texture>     m_Textures;
    std::map<std::string, sf::SoundBuffer> m_SoundBuffers;
};

#endif // ASSET_MANAGER_HPP
