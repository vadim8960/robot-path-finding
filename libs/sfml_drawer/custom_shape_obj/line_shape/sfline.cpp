//
// Created by vadim on 25.06.2021.
//

#include "sfline.h"
#include <cmath>

#ifndef COUNT_POINTS_IN_LINE
#define COUNT_POINTS_IN_LINE 10U
#endif

sf::LineShape::LineShape(float length, unsigned int width) : _length(length), _width(width) {
    update();
}

void sf::LineShape::setWidth(unsigned int width) {
    _width = width;
    update();
}

void sf::LineShape::setLength(float length) {
    _length = length;
    update();
}

unsigned int sf::LineShape::getWidth() {
    return _width;
}

float sf::LineShape::getLength() {
    return _length;
}

sf::Vector2f sf::LineShape::getStartPoints() {
    auto pos = this->getPosition();
    auto rot = this->getRotation();
    return sf::Vector2f(pos.x + std::cos(rot) * _length / 2.f, pos.y + std::sin(rot) * _length / 2.f);
}

sf::Vector2f sf::LineShape::getEndPoints() {
    auto pos = this->getPosition();
    auto rot = this->getRotation();
    return sf::Vector2f(pos.x - std::cos(rot) * _length / 2.f, pos.y - std::sin(rot) * _length / 2.f);
}

size_t sf::LineShape::getPointCount() const {
    return COUNT_POINTS_IN_LINE * _width * 2; // хз что тут пусть будет так пока что
}

sf::Vector2f sf::LineShape::getPoint(std::size_t index) const {
    float single_line_part = _length / COUNT_POINTS_IN_LINE;
    float x = 0;
    unsigned int y = 0;
    if (index / (COUNT_POINTS_IN_LINE * _width) == 0) {
        x = static_cast<float>(index % COUNT_POINTS_IN_LINE) * single_line_part;
        if ((index / COUNT_POINTS_IN_LINE) % 2)
            x = _length - x - single_line_part;
        y = index / COUNT_POINTS_IN_LINE;
    } else {
        index %= (COUNT_POINTS_IN_LINE * _width);
        x = static_cast<float>(index % COUNT_POINTS_IN_LINE) * single_line_part;
        if ((index / COUNT_POINTS_IN_LINE) % 2 == 0)
            x = _length - x - single_line_part;
        y = index / COUNT_POINTS_IN_LINE;
    }
    return sf::Vector2f(x, y);
}
