#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include <vector>

class Game {
private:
    sf::RenderWindow window;
    Paddle paddle;
    Ball ball;
    std::vector<Brick> bricks;

    void checkCollisions();
    void reset();

public:
    Game();
    void run();
};