#include <Game.hpp>

// #define GAME_FULLSCREEN

Game::Game(const sf::String& title, const unsigned int width,
           const unsigned int height)
    : m_SceneManager(std::make_unique<SceneManager>()),
      m_Clock(std::make_unique<sf::Clock>()),
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

    m_SceneManager->pushScene(ScenePtr(std::make_unique<GameScene>(m_Window.get())), true);
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
                ((event.type == sf::Event::KeyPressed) &&
                 (event.key.code == sf::Keyboard::Escape)))
        {
            m_Window->close();
            break;
        }
    }

    m_SceneManager->getActiveScene()->processInput();
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
