#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Paddle : public GameObject {
private:
    sf::RectangleShape shape;
    float speed;

public:
    Paddle(float startX, float startY);
    void update() override;
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds();
    void moveLeft();
    void moveRight();
};