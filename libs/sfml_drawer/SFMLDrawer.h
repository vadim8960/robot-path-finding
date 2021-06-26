//
// Created by vadim on 22.06.2021.
//

#ifndef ROBOT_PATH_FINDING_SFMLDRAWER_H
#define ROBOT_PATH_FINDING_SFMLDRAWER_H

#include "custom_shape_obj/CustomShapes.h"

class SFMLDrawer {

private:
    sf::RenderWindow _window;

    SFMLDrawer() = default;

    SFMLDrawer(const SFMLDrawer &s);

    SFMLDrawer &operator=(const SFMLDrawer &);

public:
    static SFMLDrawer &create();

    void init(unsigned int width, unsigned int height, const sf::String &title);

    void set_size(unsigned int width, unsigned int height);

    void set_title(const sf::String &title);

    CustomRectShape
    draw_rectangle(unsigned int width, unsigned int height, unsigned int x, unsigned int y, const sf::Color &color);

    void draw_rectangle(const CustomRectShape &rect);

    CustomCircleShape draw_circle(unsigned int r, unsigned int x, unsigned int y, const sf::Color &color);

    void draw_circle(const CustomCircleShape &circle);

    CustomLineShape
    draw_line(unsigned int w, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2,
              const sf::Color &color);

    void draw_line(const CustomLineShape &line);

    bool window_is_open();

    void window_poll_events(void (*event_handler)(sf::Event &));

    void window_update();

    void window_clear();

    void window_close();
};


#endif //ROBOT_PATH_FINDING_SFMLDRAWER_H
