#include "Triangle.hpp"

Triangle::Triangle(Coord2d coords, size_t size) : Shape(coords, size) {}

void Triangle::draw(RendererInterface* rend) {
	rend->drawLine(coords_.x() - size_, coords_.y() - size_, coords_.x() + size_, coords_.y() - size_);
	rend->drawLine(coords_.x() - size_, coords_.y() - size_, coords_.x(), coords_.y() + size_);
	rend->drawLine(coords_.x(), coords_.y() + size_, coords_.x() + size_, coords_.y() - size_);
}