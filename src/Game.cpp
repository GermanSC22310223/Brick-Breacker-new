#include "Game.h"

Game::Game()
    : window(sf::VideoMode(800, 600), "Brick Breaker"),
      paddle(400, 550),
      ball(400, 300) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            bricks.emplace_back(Brick(60 + i * 70, 40 + j * 30));
        }
    }
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        paddle.update();
        ball.update();

        checkCollisions();

        if (ball.hitBottom()) {
            reset();
        }

        window.clear();
        paddle.draw(window);
        ball.draw(window);
        for (auto& brick : bricks) {
            brick.draw(window);
        }
        window.display();
    }
}

void Game::checkCollisions() {
    if (ball.getBounds().intersects(paddle.getBounds())) {
        ball.reboundPaddle();
    }

    for (auto& brick : bricks) {
        if (!brick.isDestroyed() && ball.getBounds().intersects(brick.getBounds())) {
            ball.reboundPaddle();
            brick.destroy();
        }
    }
}

void Game::reset() {
    ball = Ball(400, 300);
}