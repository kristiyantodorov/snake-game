#include <cstdlib>
#include <ctime>

#include "CoordBounds.hpp"

class Randomizer {
public:
    Randomizer(const CoordBounds& bounds, size_t unitSize);

private:
    CoordBounds bounds_;
    size_t unitSize_;
};