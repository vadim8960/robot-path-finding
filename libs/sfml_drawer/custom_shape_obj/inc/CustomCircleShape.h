//
// Created by vadim on 26.06.2021.
//

#ifndef ROBOT_PATH_FINDING_CUSTOMCIRCLESHAPE_H
#define ROBOT_PATH_FINDING_CUSTOMCIRCLESHAPE_H

#include "SFML/Graphics.hpp"
#include "AbstractCustomShape.h"

class CustomCircleShape : public AbstractCustomShape {
    sf::CircleShape _shape;
    unsigned int _rad;
    sf::Vector2u _pos;

public:
    CustomCircleShape(unsigned int rad, const sf::Vector2u &pos);

    void set_color(const sf::Color &color) override;

    const sf::Drawable &get_drawable_inst() const override;

    unsigned int get_radius() const;

    const sf::Vector2u &get_position() const;
};


#endif //ROBOT_PATH_FINDING_CUSTOMCIRCLESHAPE_H
