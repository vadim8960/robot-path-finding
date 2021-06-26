//
// Created by vadim on 26.06.2021.
//

#include "inc/CustomCircleShape.h"

CustomCircleShape::CustomCircleShape(unsigned int rad, const sf::Vector2u &pos) : _rad(rad), _pos(pos) {
    _shape.setRadius(static_cast<float>(rad));
    _shape.setPosition({static_cast<float>(pos.x), static_cast<float>(pos.y)});
    _shape.setFillColor(sf::Color::White);
}

void CustomCircleShape::set_color(const sf::Color &color) {
    _shape.setFillColor(color);
}

const sf::Drawable &CustomCircleShape::get_drawable_inst() const {
    return _shape;
}


unsigned int CustomCircleShape::get_radius() const {
    return _rad;
}

const sf::Vector2u &CustomCircleShape::get_position() const {
    return _pos;
}