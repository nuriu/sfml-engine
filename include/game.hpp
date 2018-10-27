#include <memory>
#include <SFML/Graphics.hpp>

class Game
{
  public:
    Game(const sf::String &title, const unsigned int width, const unsigned int height);

    void run();

  private:
    void processEvents();
    void update();
    void render();

  private:
    std::unique_ptr<sf::RenderWindow> m_Window;
    std::unique_ptr<sf::CircleShape> m_Shape;
};
