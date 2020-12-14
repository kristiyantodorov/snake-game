#include "Snake.hpp"

Snake::Snake(const CoordBounds& bounds) : bounds_(bounds) {}

Snake::Snake(const Coord2d& startPos, const CoordBounds& bounds, size_t unitSize) : bounds_(bounds), unitSize_(unitSize), shouldGrow_(false) {
    positions_.push_back(std::make_shared<Rectangle>(startPos, unitSize_));
}

void Snake::draw(RendererInterface* rend) {
    for(auto pos : positions_) {
        pos->draw(rend);
    }
}

void Snake::move(Directions dir) {
    if (dir == Directions::NONE) return;

    for(size_t i = 0; i < positions_.size(); i++) {
        printf("%d, %d\n", positions_[i]->getCoords().x(), positions_[i]->getCoords().y());
    }

    Coord2d lastPos = positions_[positions_.size()-1]->getCoords();

    for(size_t i = positions_.size()-1; i > 0; --i) {
        positions_[i]->setCoords(positions_[i-1]->getCoords());
    }
    Coord2d delta = calculateNext(dir);
    positions_[0]->move(delta.x(), delta.y());

    if ( shouldGrow_ )
        addPosition(lastPos);

    if ( !validatePosition(positions_[0]->getCoords()) ) throw std::out_of_range("Out of bounds");
}

void Snake::grow() {
    shouldGrow_ = true;
}

void Snake::addPosition(const Coord2d& newPos) {
    positions_.push_back(std::make_shared<Rectangle>(newPos, unitSize_));
    shouldGrow_ = false;
}

Coord2d Snake::calculateNext(Directions dir) const {
    int x, y;

    switch(dir) {
        case Directions::RIGHT:
            x = unitSize_;
            y = 0;
            break;
        case Directions::UP:
            x = 0;
            y = -unitSize_;
            break;
        case Directions::LEFT:
            x = -unitSize_;
            y = 0;
            break;
        case Directions::DOWN:
            x = 0;
            y = unitSize_;
            break;
    }
    return Coord2d(x, y);
}

bool Snake::validatePosition(const Coord2d& position) const {
    bool cannibalism = partOfSnake(position);

    return bounds_.inBounds(position) && !cannibalism;
}

Coord2d Snake::headPosition() const {
    return positions_[0]->getCoords();
}

bool Snake::partOfSnake(const Coord2d& pos) const {
    for ( size_t i=1; i < positions_.size(); i++ ) {
        if ( positions_[0]->getCoords() == positions_[i]->getCoords() ) {
            return true;
        }
    }
    return false;
}

Snake::~Snake() {
}