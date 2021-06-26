//
// Created by vadim on 26.06.2021.
//

#include "../inc/CustomRectShape.h"

CustomRectShape::CustomRectShape(unsigned int width, unsigned int height, const sf::Vector2u &start_point) : _width(
        width), _height(height), _sp(start_point) {
    _shape.setSize(sf::Vector2f({static_cast<float>(width), static_cast<float>(height)}));
    _shape.setPosition(sf::Vector2f(start_point));
    _shape.setFillColor(sf::Color::White);
}

void CustomRectShape::set_color(const sf::Color &color) {
    _shape.setFillColor(color);
}

const sf::Drawable &CustomRectShape::get_drawable_inst() const {
    return _shape;
}

unsigned int CustomRectShape::get_width() const {
    return _width;
}

unsigned int CustomRectShape::get_height() const {
    return _height;
}

const sf::Vector2u &CustomRectShape::get_start_point() const {
    return _sp;
}
