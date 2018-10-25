#include <SFML/Graphics.hpp>

// #define DESKTOP_FULLSCREEN

int main()
{

#ifdef DESKTOP_FULLSCREEN
    auto desktop = sf::VideoMode::getDesktopMode();
    auto windowMode = sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel);
    sf::RenderWindow window(windowMode, "Game", sf::Style::Fullscreen);
#else
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game");
#endif

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(window.getSize().x / 2 - shape.getRadius(),
                      window.getSize().y / 2 - shape.getRadius());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return EXIT_SUCCESS;
}