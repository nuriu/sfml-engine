#include <memory>

#include <Engine/Application.hpp>
#include <Game/Scenes/GameScene.hpp>

int main()
{
    auto game = std::make_unique<Engine::Application>("GAME", 1280, 768);

    game->run<GameScene>();

    return EXIT_SUCCESS;
}
