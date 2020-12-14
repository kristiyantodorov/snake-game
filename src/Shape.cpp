#include "Shape.hpp"

Shape::Shape(Coord2d coords, size_t size) : coords_(coords), size_(size) {}
Coord2d Shape::getCoords() const {
    return coords_;
}
void Shape::setCoords(const Coord2d& coords) {
    coords_ = coords;
}