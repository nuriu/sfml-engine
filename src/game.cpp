#include "game.hpp"

// #define GAME_FULLSCREEN

Game::Game(const sf::String &title, const unsigned int width, const unsigned int height)
{
#ifdef GAME_FULLSCREEN
    auto desktop = sf::VideoMode::getDesktopMode();
    auto windowMode = sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel);
    m_Window = std::make_unique<sf::RenderWindow>(windowMode, title, sf::Style::Fullscreen);
#else
    m_Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), title);
#endif

    m_Shape = std::make_unique<sf::CircleShape>(100.f);

    m_Shape->setFillColor(sf::Color::Red);
    m_Shape->setPosition(m_Window->getSize().x / 2 - m_Shape->getRadius(),
                         m_Window->getSize().y / 2 - m_Shape->getRadius());
}

void Game::run()
{
    while (m_Window->isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (m_Window->pollEvent(event))
    {
        if ((event.type == sf::Event::Closed) ||
            ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
        {
            m_Window->close();
            break;
        }
    }
}

void Game::update()
{
}

void Game::render()
{
    m_Window->clear();
    m_Window->draw(*m_Shape);
    m_Window->display();
}
