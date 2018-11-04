#include <GameScene.hpp>

GameScene::GameScene(sf::RenderWindow* window)
    : m_RenderWindow(window),
      m_InputManager(std::make_unique<InputManager>()),
      m_Shape(std::make_unique<sf::CircleShape>())
{

}

void GameScene::initialize()
{
    m_Shape->setRadius(100.f);
    m_Shape->setFillColor(sf::Color::Magenta);
    m_Shape->setPosition(m_RenderWindow->getSize().x / 2.f - m_Shape->getRadius(),
                         m_RenderWindow->getSize().y / 2.f - m_Shape->getRadius());
}

void GameScene::processInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed &&
            m_InputManager->isKeyPressed(sf::Keyboard::H))
    {
        std::cout << "H is pressed." << std::endl;
    }
}

void GameScene::update(float deltaTime)
{
}

void GameScene::render() const
{
    m_RenderWindow->draw(*m_Shape);
}

void GameScene::pause()
{
}

void GameScene::resume()
{
}
