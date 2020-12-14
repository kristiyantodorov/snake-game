#pragma once

class Coord2d {
public:
    Coord2d(int x, int y);
    Coord2d& translate(int dx, int dy);
    bool operator==(const Coord2d& rhs) const;

    inline int x() const { return x_; }
    inline int y() const { return y_; }

private:
    int x_, y_;
};