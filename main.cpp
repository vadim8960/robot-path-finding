#include <SFMLDrawer.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    sf::Image image;
    image.create(1000, 1000);
    sf::Sprite sprite;
    sf::Texture texture;

    sf::LineShape line(60, 5);
    line.setPosition(20, 20);
    line.setFillColor(sf::Color::Red);

    sf::CircleShape shape(100.f);
    sf::RectangleShape shape2({15, 15});
    shape2.setPosition(20, 20);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
//        window.draw(shape);
//        window.draw(shape2);
        window.draw(line);
        window.display();
    }

    return 0;
}