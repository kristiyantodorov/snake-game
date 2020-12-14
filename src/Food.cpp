#include "Food.hpp"

Food::Food(const CoordBounds& bounds) : bounds_(bounds) {}

Food::Food(const Coord2d& coords, size_t unitSize) : position_(coords, unitSize) {}

void Food::draw(RendererInterface* rend) {
    position_.draw(rend);
}

Coord2d Food::getPosition() const {
    return position_.getCoords();
}

void Food::setRandomPos() {

}