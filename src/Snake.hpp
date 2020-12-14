#include <vector>
#include <memory>

#include "Rectangle.hpp"
#include "CoordBounds.hpp"

enum class Directions {
    NONE=0,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {
public:
    Snake(const CoordBounds& bounds);
    Snake(const Coord2d& startPos, const CoordBounds& bounds, size_t unitSize=50);
    void draw(RendererInterface* rend);
    void move(Directions dir);
    void grow();
    Coord2d headPosition() const;
    ~Snake();

private:
    Coord2d calculateNext(Directions dir) const;
    bool validatePosition(const Coord2d& position) const;
    void addPosition(const Coord2d& newPos);
    bool partOfSnake(const Coord2d& pos) const;

    CoordBounds bounds_;
    const size_t unitSize_ = 20;
    bool shouldGrow_;

    std::vector<std::shared_ptr<Rectangle> > positions_;
};