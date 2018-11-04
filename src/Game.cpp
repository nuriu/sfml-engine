#include <Game.hpp>

// #define GAME_FULLSCREEN

Game::Game(const sf::String& title, const unsigned int width,
           const unsigned int height)
    : m_SceneManager(std::make_unique<SceneManager>()),
      m_Clock(std::make_unique<sf::Clock>()),
      m_Event(std::make_unique<sf::Event>()),
      m_DeltaTime(0.f)
{
#ifdef GAME_FULLSCREEN
    auto desktop = sf::VideoMode::getDesktopMode();
    auto windowMode = sf::VideoMode(desktop.width, desktop.height,
                                    desktop.bitsPerPixel);
    m_Window = std::make_unique<sf::RenderWindow>(windowMode, title,
               sf::Style::Fullscreen);
#else
    m_Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height),
               title);
#endif

    m_SceneManager->pushScene(
        ScenePtr(std::make_unique<GameScene>(m_Window.get())), true
    );
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
    while (m_Window->pollEvent(*m_Event))
    {
        if ((m_Event->type == sf::Event::Closed) ||
                ((m_Event->type == sf::Event::KeyPressed) &&
                 (m_Event->key.code == sf::Keyboard::Escape)))
        {
            m_Window->close();
            break;
        }

        m_SceneManager->getActiveScene()->processInput(*m_Event);
    }
}

void Game::update()
{
    m_DeltaTime = m_Clock->restart().asSeconds();

    m_SceneManager->getActiveScene()->update(m_DeltaTime);
}

void Game::render()
{
    m_Window->clear();

    m_SceneManager->getActiveScene()->render();

    m_Window->display();
}
