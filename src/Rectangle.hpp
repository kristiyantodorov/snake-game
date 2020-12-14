#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle : public Shape {
public:
    Rectangle(Coord2d coords, size_t size);
    void draw(RendererInterface* rend) override;
    void move(int dx, int dy) override;
    void moveTo(const Coord2d& pos) override;
};

#endif