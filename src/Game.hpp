#pragma once

#include "Snake.hpp"
#include "Food.hpp"
#include "RendererInterface.hpp"
#include "CoordBounds.hpp"

class Game {
public:
    Game(RendererInterface* renderer, size_t width, size_t height, size_t unitSize);

    void drawFrame(Directions dir);

private:
    RendererInterface* renderer_;
    Snake snake_;
    Food food_;
    CoordBounds bounds_;
};