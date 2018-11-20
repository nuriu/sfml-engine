#include <Scenes/GameScene.hpp>

GameScene::GameScene(const CoreComponents& components)
    : m_Components(components)
    , m_Shape(std::make_unique<sf::CircleShape>())
{
}

void GameScene::initialize()
{
    m_Shape->setRadius(100.f);
    m_Shape->setFillColor(sf::Color::Magenta);
    m_Shape->setPosition(m_Components.m_RenderWindow->getSize().x / 2.f - m_Shape->getRadius(),
                         m_Components.m_RenderWindow->getSize().y / 2.f - m_Shape->getRadius());
}

void GameScene::processInput()
{
    if (m_Components.m_InputManager->isKeyPressed(sf::Keyboard::H))
    {
        std::cout << "H is pressed." << std::endl;
    }
}

void GameScene::update() {}

void GameScene::render() const
{
    m_Components.m_RenderWindow->draw(*m_Shape);
}

void GameScene::pause() {}

void GameScene::resume() {}
