//
// Created by vadim on 26.06.2021.
//

#ifndef ROBOT_PATH_FINDING_ABSTRACTCUSTOMSHAPE_H
#define ROBOT_PATH_FINDING_ABSTRACTCUSTOMSHAPE_H

#include "SFML/Graphics.hpp"

class AbstractCustomShape {
protected:
    virtual void set_color(const sf::Color &color) = 0;
    virtual const sf::Drawable &get_drawable_inst() const = 0;
};


#endif //ROBOT_PATH_FINDING_ABSTRACTCUSTOMSHAPE_H
