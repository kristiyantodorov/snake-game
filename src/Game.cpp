
#include "Game.hpp"

Game::Game(RendererInterface* renderer, size_t width, size_t height, size_t unitSize)
    : renderer_(renderer), bounds_(0, width * unitSize, 0, height * unitSize), snake_(bounds_), food_(bounds_) {}

void Game::drawFrame(Directions dir) {
    snake_.move(dir);
    if ( snake_.headPosition() == food_.getPosition() )
        snake_.grow();
    snake_.draw(renderer_);
    food_.draw(renderer_);
}