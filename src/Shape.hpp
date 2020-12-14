#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cstddef>

#include "Coord2d.hpp"
#include "RendererInterface.hpp"

class Shape {
public:
    Shape(Coord2d coords, size_t size);

    virtual void draw(RendererInterface* rend) = 0;
    virtual void move(int dx, int dy) = 0;
    virtual void moveTo(const Coord2d& pos) = 0;
    Coord2d getCoords() const;
    void setCoords(const Coord2d& coords);

    virtual ~Shape() = default;
protected:
    Coord2d coords_;
    size_t size_;
};

#endif