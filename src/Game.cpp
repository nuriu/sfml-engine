#include <Game.hpp>

// #define GAME_FULLSCREEN

Game::Game(const sf::String& title, const unsigned int width, const unsigned int height)
    : m_Components(std::make_shared<CoreComponents>()), m_Clock(std::make_unique<sf::Clock>())
{
#ifdef GAME_FULLSCREEN
    auto desktop    = sf::VideoMode::getDesktopMode();
    auto windowMode = sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel);
    m_Components->m_RenderWindow =
        std::make_unique<sf::RenderWindow>(windowMode, title, sf::Style::Fullscreen);
#else
    sf::VideoMode vm(width, height);
    m_Components->m_RenderWindow = std::make_unique<sf::RenderWindow>(vm, title);
#endif
    m_Components->m_RenderWindow->setVerticalSyncEnabled(true);
    m_Components->m_RenderWindow->setFramerateLimit(60);

    ImGui::SFML::Init(*m_Components->m_RenderWindow);

    m_Components->m_SceneManager->pushScene(ScenePtr(std::make_unique<GameScene>(*m_Components)),
                                            true);
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
    while (m_Components->m_RenderWindow->pollEvent(*m_Components->m_InputManager->m_Event))
    {
        ImGui::SFML::ProcessEvent(*m_Components->m_InputManager->m_Event);

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
    *m_Components->m_DeltaTime = m_Clock->restart();

    ImGui::SFML::Update(*m_Components->m_RenderWindow, *m_Components->m_DeltaTime);

    m_Components->m_SceneManager->getActiveScene()->update();
}

void Game::render()
{
    ImGui::Begin("Hello, world!");
    ImGui::Button("Look at this pretty button");
    ImGui::End();

    m_Components->m_RenderWindow->clear();
    m_Components->m_SceneManager->getActiveScene()->render();

    ImGui::SFML::Render(*m_Components->m_RenderWindow);

    m_Components->m_RenderWindow->display();
}
