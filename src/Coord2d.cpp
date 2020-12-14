#include "Coord2d.hpp"

Coord2d::Coord2d(int x, int y) : x_(x), y_(y) {}

Coord2d& Coord2d::translate(int dx, int dy) {
    x_ += dx;
    y_ += dy;

    return *this;
}

bool Coord2d::operator==(const Coord2d& rhs) const {
    return this->x_ == rhs.x_ && this->y_ == rhs.y_;
}