#include "Brick.hpp"

Brick::Brick(float startX, float startY) {
    shape.setPosition(startX, startY);
    shape.setSize({ 60, 20 });
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(30, 10);
    destroyed = false;
}

void Brick::update() {
    // No specific update logic for bricks
}

void Brick::draw(sf::RenderWindow& window) {
    if (!destroyed) {
        window.draw(shape);
    }
}

sf::FloatRect Brick::getBounds() {
    return shape.getGlobalBounds();
}

bool Brick::isDestroyed() {
    return destroyed;
}

void Brick::destroy() {
    destroyed = true;
}