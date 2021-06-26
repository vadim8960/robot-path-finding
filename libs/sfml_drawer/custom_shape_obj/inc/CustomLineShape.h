//
// Created by vadim on 26.06.2021.
//

#ifndef ROBOT_PATH_FINDING_CUSTOMLINESHAPE_H
#define ROBOT_PATH_FINDING_CUSTOMLINESHAPE_H

#include "SFML/Graphics.hpp"
#include "AbstractCustomShape.h"

enum CustomLineShapeType{
    CUSTOM_LINE_SHAPE_TYPE_THIN = 0U,
    CUSTOM_LINE_SHAPE_TYPE_THICK
} ;

class CustomLineShape : AbstractCustomShape {
    sf::Vector2u _sp;
    sf::Vector2u _ep;
    unsigned int _width;
    float _length;
    sf::Vertex _thin_line[2];
    sf::RectangleShape _thick_line;
    CustomLineShapeType _line_type;

public:
    CustomLineShape(const sf::Vector2u &start_point, const sf::Vector2u &end_point, unsigned int width);

    void set_color(const sf::Color &color) override;

    const sf::Drawable &get_drawable_inst() const override;

    const sf::Vertex *get_vertexs_inst() const;

    unsigned int get_width() const;

    const sf::Vector2u &get_start_point() const;

    const sf::Vector2u &get_end_point() const;

    CustomLineShapeType get_line_type() const;

    float get_length() const;
};


#endif //ROBOT_PATH_FINDING_CUSTOMLINESHAPE_H
