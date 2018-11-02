#include <GameScene.hpp>

GameScene::GameScene(sf::RenderWindow* window)
    : m_RenderWindow(window),
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

void GameScene::processInput()
{
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
