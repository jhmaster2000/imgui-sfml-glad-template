#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include "baseactor.h"
#include "log.h"

class RectActor : public BaseActor {
public:
    RectActor(float size)
    : BaseActor(new sf::RectangleShape(sf::Vector2f(size, size))) {}

    RectActor(float width, float height)
    : BaseActor(new sf::RectangleShape(sf::Vector2f(width, height))) {}

    RectActor(const sf::Vector2f& dimensions)
    : BaseActor(new sf::RectangleShape(dimensions)) {}

    virtual ~RectActor() {}
};
