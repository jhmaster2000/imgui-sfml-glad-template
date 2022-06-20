#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include "baseactor.h"
#include "log.h"

class CircleActor : public BaseActor {
public:
    CircleActor(float radius, size_t pointCount = 30ULL)
    : BaseActor(new sf::CircleShape(radius, pointCount)) {}

    virtual ~CircleActor() {}
};
