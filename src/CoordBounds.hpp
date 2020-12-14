#pragma once

#include "Coord2d.hpp"

struct CoordBounds {
    CoordBounds(int x1, int x2, int y1, int y2) : x1(x1), x2(x2), y1(y1), y2(y2) {}

    bool inBounds(Coord2d coords) const {
        return x1 <= coords.x() && coords.x() <= x2 && y1 <= coords.y() && coords.y() <= y2;
    }

    int x1, x2, y1, y2;
};