#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Ball : public GameObject {
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float speed;

public:
    Ball(float startX, float startY);
    void update() override;
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds();
    void reboundPaddle();
    void reboundSides();
    void reboundTop();
    bool hitBottom();
    void move();
};