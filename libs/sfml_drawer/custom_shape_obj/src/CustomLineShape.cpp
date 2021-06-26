//
// Created by vadim on 26.06.2021.
//

#include "inc/CustomLineShape.h"
#include <cmath>

#define RAD_TO_DEG(RAD) (RAD * (180.0/M_PI))

CustomLineShape::CustomLineShape(const sf::Vector2u &start_point, const sf::Vector2u &end_point, unsigned int width)
        : _sp(start_point), _ep(end_point), _width(width) {
    sf::VertexBuffer buf;
    _length = std::sqrt((_sp.x - _ep.x) * (_sp.x - _ep.x) + (_sp.y - _ep.y) * (_sp.y - _ep.y));
    if (_width == 1) {
        _line_type = CUSTOM_LINE_SHAPE_TYPE_THIN;
        _thin_line[0] = (sf::Vector2f(_sp));
        _thin_line[0].color = sf::Color::White;
        _thin_line[1] = (sf::Vector2f(_ep));
        _thin_line[1].color = sf::Color::White;
    } else {
        _line_type = CUSTOM_LINE_SHAPE_TYPE_THICK;
        double angle = std::atan2(static_cast<double>(_ep.y) - static_cast<double>(_sp.y),
                                 static_cast<double>(_ep.x) - static_cast<double>(_sp.x));
        _thick_line.setSize(sf::Vector2f(_length, _width));
        _thick_line.setOrigin({_length / 2, static_cast<float>(_width) / 2});
        _thick_line.setPosition({(static_cast<float>(_sp.x) + static_cast<float>(_ep.x)) / 2.f,
                                 (static_cast<float>(_sp.y) + static_cast<float>(_ep.y)) / 2.f});
        _thick_line.setRotation(RAD_TO_DEG(angle));
        _thick_line.setFillColor(sf::Color::White);
    }
}

void CustomLineShape::set_color(const sf::Color &color) {
    switch (_line_type) {
        case CUSTOM_LINE_SHAPE_TYPE_THIN:
            _thin_line[0].color = color;
            _thin_line[1].color = color;
            break;

        case CUSTOM_LINE_SHAPE_TYPE_THICK:
            _thick_line.setFillColor(color);
            break;
    }
}

const sf::Drawable &CustomLineShape::get_drawable_inst() const {
    return _thick_line;
}

const sf::Vertex *CustomLineShape::get_vertexs_inst() const {
    return _thin_line;
}

unsigned int CustomLineShape::get_width() const {
    return _width;
}

const sf::Vector2u &CustomLineShape::get_start_point() const {
    return _sp;
}

const sf::Vector2u &CustomLineShape::get_end_point() const {
    return _ep;
}

CustomLineShapeType CustomLineShape::get_line_type() const {
    return _line_type;
}

float CustomLineShape::get_length() const {
    return _length;
}
