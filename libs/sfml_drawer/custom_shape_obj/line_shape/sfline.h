//
// Created by vadim on 25.06.2021.
//

#ifndef ROBOT_PATH_FINDING_SFLINE_H
#define ROBOT_PATH_FINDING_SFLINE_H

#include "SFML/Graphics.hpp"

namespace sf {
    class LineShape : public sf::Shape {
    private:
        float _length;
        unsigned int _width;
    public:
        explicit LineShape(float length, unsigned int width);

        void setWidth(unsigned int width);

        void setLength(float length);

        unsigned int getWidth();

        float getLength();

        sf::Vector2f getStartPoints();

        sf::Vector2f getEndPoints();

        size_t getPointCount() const override;

        sf::Vector2f getPoint(std::size_t index) const override;
    };
}

#endif //ROBOT_PATH_FINDING_SFLINE_H
