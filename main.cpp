#include <SFMLDrawer.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 400), "SFML works!");

    sf::Image image;
    image.create(1000, 1000);
    sf::Sprite sprite;
    sf::Texture texture;

    sf::LineShape line(10, 2);
    line.setPosition(20, 20);
    line.setFillColor(sf::Color::Red);
    line.setRotation(15);
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
        window.draw(line);
//        window.draw(shape2);
        window.display();
    }

    return 0;
}