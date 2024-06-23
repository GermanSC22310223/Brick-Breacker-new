#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};