//
// Created by vadim on 26.06.2021.
//

#ifndef ROBOT_PATH_FINDING_CUSTOMRECTSHAPE_H
#define ROBOT_PATH_FINDING_CUSTOMRECTSHAPE_H

#include "SFML/Graphics.hpp"
#include "AbstractCustomShape.h"

class CustomRectShape : public AbstractCustomShape {
    unsigned int _width;
    unsigned int _height;
    sf::Vector2u _sp;
    sf::RectangleShape _shape;

public:
    CustomRectShape(unsigned int width, unsigned int height, const sf::Vector2u &start_point);

    void set_color(const sf::Color &color) override;

    const sf::Drawable &get_drawable_inst() const override;

    unsigned int get_width() const;

    unsigned int get_height() const;

    const sf::Vector2u &get_start_point() const;
};


#endif //ROBOT_PATH_FINDING_CUSTOMRECTSHAPE_H
