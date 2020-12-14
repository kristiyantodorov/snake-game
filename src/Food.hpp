#pragma once

#include "Rectangle.hpp"
#include "CoordBounds.hpp"

class Food {
public:
    Food(const CoordBounds& bounds);
    Food(const Coord2d& coords, size_t unitSize);
    void draw(RendererInterface* rend);
    Coord2d getPosition() const;
    void setRandomPos();
private:
    Rectangle position_;
    CoordBounds bounds_;
};