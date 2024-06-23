#include "Ball.hpp"

Ball::Ball(float startX, float startY) {
    shape.setPosition(startX, startY);
    shape.setRadius(10);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(10, 10);
    velocity = { -6.0f, -6.0f };
    speed = 6.0f;
}

void Ball::update() {
    shape.move(velocity);
    if (getBounds().left < 0 || getBounds().left + getBounds().width > 800) {
        reboundSides();
    }
    if (getBounds().top < 0) {
        reboundTop();
    }
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Ball::getBounds() {
    return shape.getGlobalBounds();
}

void Ball::reboundPaddle() {
    velocity.y = -velocity.y;
}

void Ball::reboundSides() {
    velocity.x = -velocity.x;
}

void Ball::reboundTop() {
    velocity.y = -velocity.y;
}

bool Ball::hitBottom() {
    return shape.getPosition().y > 600;
}