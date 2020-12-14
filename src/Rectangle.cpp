#include "Rectangle.hpp"

Rectangle::Rectangle(Coord2d coords, size_t size) : Shape(coords, size) {}

void Rectangle::draw(RendererInterface* rend) {
		rend->drawLine(coords_.x(), coords_.y(), coords_.x() + size_, coords_.y());
		rend->drawLine(coords_.x() + size_, coords_.y(), coords_.x() + size_, coords_.y() + size_);
		rend->drawLine(coords_.x() + size_, coords_.y() + size_, coords_.x(), coords_.y() + size_);
		rend->drawLine(coords_.x(), coords_.y() + size_, coords_.x(), coords_.y());
}

void Rectangle::move(int dx, int dy) {
	coords_.translate(dx, dy);
}

void Rectangle::moveTo(const Coord2d& pos) {
	coords_ = pos;
}