#include "SFMLDrawer.h"

void event_handler(sf::Event &event) {
    SFMLDrawer &sfml = SFMLDrawer::create();
    if (event.type == sf::Event::Closed) {
        sfml.window_close();
    }
}

int main() {
    SFMLDrawer &sfml_drawer = SFMLDrawer::create();
    sfml_drawer.init(200, 200, "Hello");
    auto rect = sfml_drawer.draw_rectangle(10, 10, 10, 10, sf::Color::White);
    auto circle = sfml_drawer.draw_circle(10, 20, 20, sf::Color::Yellow);
    auto line1 = sfml_drawer.draw_line(1, 50, 50, 100, 100, sf::Color::Magenta);
    auto line2 = sfml_drawer.draw_line(15, 100, 100, 200, 159, sf::Color::Green);
    sfml_drawer.window_update();
    while (sfml_drawer.window_is_open()) {
        sfml_drawer.window_poll_events(event_handler);
        sfml_drawer.window_clear();
        sfml_drawer.draw_circle(circle);
        sfml_drawer.draw_line(line2);
        sfml_drawer.draw_line(line1);
        sfml_drawer.draw_rectangle(rect);
        sfml_drawer.window_update();
    }
    return 0;
}