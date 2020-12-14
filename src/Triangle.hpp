#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"

class Triangle : public Shape {
public:
    Triangle(Coord2d coords, size_t size);
    void draw(RendererInterface* rend) override;
};

#endif