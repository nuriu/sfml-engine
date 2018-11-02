#include <memory>

#include <Game.hpp>

int main()
{
    std::unique_ptr<Game> game(new Game("Game", 1280, 720));

    game->run();

    return EXIT_SUCCESS;
}
