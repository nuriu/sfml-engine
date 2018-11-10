#include <Game.hpp>

// #define GAME_FULLSCREEN

Game::Game(const sf::String& title, const unsigned int width,
           const unsigned int height)
    : m_Components(std::make_shared<CoreComponents>()),
      m_Clock(std::make_unique<sf::Clock>())
{
#ifdef GAME_FULLSCREEN
    auto desktop = sf::VideoMode::getDesktopMode();
    auto windowMode = sf::VideoMode(desktop.width, desktop.height,
                                    desktop.bitsPerPixel);
    m_Components->m_RenderWindow = std::make_unique<sf::RenderWindow>(windowMode,
                                   title, sf::Style::Fullscreen);
#else
    m_Components->m_RenderWindow = std::make_unique<sf::RenderWindow>(
                                       sf::VideoMode(width, height), title);
#endif

    m_Components->m_SceneManager->pushScene(
        ScenePtr(std::make_unique<GameScene>(*m_Components)), true
    );
}

void Game::run()
{
    while (m_Components->m_RenderWindow->isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    while (m_Components->m_RenderWindow->pollEvent(
                *m_Components->m_InputManager->m_Event))
    {
        if (m_Components->m_InputManager->m_Event->type == sf::Event::Closed ||
                m_Components->m_InputManager->isKeyPressed(sf::Keyboard::Escape))
        {
            m_Components->m_RenderWindow->close();
            break;
        }

        m_Components->m_SceneManager->getActiveScene()->processInput();
    }
}

void Game::update()
{
    m_Components->m_DeltaTime = m_Clock->restart().asSeconds();
    m_Components->m_SceneManager->getActiveScene()->update();
}

void Game::render()
{
    m_Components->m_RenderWindow->clear();
    m_Components->m_SceneManager->getActiveScene()->render();
    m_Components->m_RenderWindow->display();
}
