#include <Game/Scenes/GameScene.hpp>

GameScene::GameScene(const Engine::Components& components)
    : m_Components(components), m_Shape(std::make_unique<sf::CircleShape>())
{
}

void GameScene::initialize()
{
    m_Shape->setRadius(100.f);
    m_Shape->setFillColor(sf::Color::Magenta);
    m_Shape->setPosition(m_Components.m_RenderWindow->getSize().x / 2.f - m_Shape->getRadius(),
                         m_Components.m_RenderWindow->getSize().y / 2.f - m_Shape->getRadius());
}

void GameScene::processInput() {}

void GameScene::update() {}

void GameScene::render() const
{
    ImGui::Begin("Hello, GAME!");
    ImGui::Button("github.com/nuriu/sfml-cmake-vscode");
    ImGui::End();

    m_Components.m_RenderWindow->draw(*m_Shape);
}

void GameScene::pause() {}

void GameScene::resume() {}
