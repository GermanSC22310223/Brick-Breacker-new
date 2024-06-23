#include "Paddle.hpp"

Paddle::Paddle(float startX, float startY) {
    shape.setPosition(startX, startY);
    shape.setSize({100, 20});
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(50, 10);
    speed = 6.0f;
}

void Paddle::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && getBounds().left > 0) {
        moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && getBounds().left + getBounds().width < 800) {
        moveRight();
    }
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Paddle::getBounds() {
    return shape.getGlobalBounds();
}

void Paddle::moveLeft() {
    shape.move(-speed, 0);
}

void Paddle::moveRight() {
    shape.move(speed, 0);
}