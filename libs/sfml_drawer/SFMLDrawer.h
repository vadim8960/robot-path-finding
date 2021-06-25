//
// Created by vadim on 22.06.2021.
//

#ifndef ROBOT_PATH_FINDING_SFMLDRAWER_H
#define ROBOT_PATH_FINDING_SFMLDRAWER_H

#include "SFML/Graphics.hpp"
#include "sfline.h"

class SFMLDrawer {

private:
    sf::Image _image;
    sf::Texture _texture;
    sf::RenderWindow _window;

protected:
    SFMLDrawer() = default;

public:
    SFMLDrawer(const SFMLDrawer &s) = delete;

    SFMLDrawer &operator=(const SFMLDrawer &) = delete;

    static SFMLDrawer &create(int width, int height, sf::String title);

    void set_size(int width, int height);

    void set_title(sf::String title);

    sf::RectangleShape draw_rectangle(int width, int height, int x, int y, sf::Color color);

    sf::CircleShape draw_circle(int r, int x, int y, sf::Color color);

    sf::RectangleShape draw_line(int w, int x1, int y1, int x2, int y2, sf::Color color);

    bool window_is_open();

    void window_poll_events(void (*event_handler)(sf::Event &));

    void window_update();

    void window_clear();

    void window_close();


};


#endif //ROBOT_PATH_FINDING_SFMLDRAWER_H
