#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Brick : public GameObject {
private:
    sf::RectangleShape shape;
    bool destroyed;

public:
    Brick(float startX, float startY);
    void update() override;
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds();
    bool isDestroyed();
    void destroy();
};