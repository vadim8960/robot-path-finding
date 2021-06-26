//
// Created by vadim on 22.06.2021.
//

#include "SFMLDrawer.h"

SFMLDrawer &SFMLDrawer::create() {
    static SFMLDrawer inst;
    return inst;
}

void SFMLDrawer::init(unsigned int width, unsigned int height, const sf::String &title) {
    _window.create(sf::VideoMode(width, height), title);
}

void SFMLDrawer::set_size(unsigned int width, unsigned int height) {
    _window.setSize({width, height});
}

void SFMLDrawer::set_title(const sf::String &title) {
    _window.setTitle(title);
}

CustomRectShape
SFMLDrawer::draw_rectangle(unsigned int width, unsigned int height, unsigned int x, unsigned int y,
                           const sf::Color &color) {
    CustomRectShape retv(width, height, sf::Vector2u({x, y}));
    retv.set_color(color);
    _window.draw(retv.get_drawable_inst());
    return retv;
}

void SFMLDrawer::draw_rectangle(const CustomRectShape &rect) {
    _window.draw(rect.get_drawable_inst());
}

CustomCircleShape SFMLDrawer::draw_circle(unsigned int r, unsigned int x, unsigned int y, const sf::Color &color) {
    CustomCircleShape retv(r, sf::Vector2u({x, y}));
    retv.set_color(color);
    _window.draw(retv.get_drawable_inst());
    return retv;
}

void SFMLDrawer::draw_circle(const CustomCircleShape &circle) {
    _window.draw(circle.get_drawable_inst());
}

CustomLineShape
SFMLDrawer::draw_line(unsigned int w, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2,
                      const sf::Color &color) {
    CustomLineShape retv({x1, y1}, {x2, y2}, w);
    retv.set_color(color);
    switch (retv.get_line_type()) {
        case CUSTOM_LINE_SHAPE_TYPE_THIN:
            _window.draw(retv.get_vertexs_inst(), 2, sf::Lines);
            break;
        case CUSTOM_LINE_SHAPE_TYPE_THICK:
            _window.draw(retv.get_drawable_inst());
            break;
    }
    return retv;
}

void SFMLDrawer::draw_line(const CustomLineShape &line) {
    switch (line.get_line_type()) {
        case CUSTOM_LINE_SHAPE_TYPE_THIN:
            _window.draw(line.get_vertexs_inst(), 2, sf::Lines);
            break;
        case CUSTOM_LINE_SHAPE_TYPE_THICK:
            _window.draw(line.get_drawable_inst());
            break;
    }
}

bool SFMLDrawer::window_is_open() {
    return _window.isOpen();
}

void SFMLDrawer::window_poll_events(void (*event_handler)(sf::Event &)) {
    sf::Event event{};
    while (_window.pollEvent(event)) {
        event_handler(event);
    }
}

void SFMLDrawer::window_update() {
    _window.display();
}

void SFMLDrawer::window_clear() {
    _window.clear();
}

void SFMLDrawer::window_close() {
    _window.close();
}
