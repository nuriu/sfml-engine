#include <memory>

#include <Core/Game.hpp>

int main()
{
    std::unique_ptr<Game> game(new Game("Game", 1280, 768));

    game->run();

    return EXIT_SUCCESS;
}
