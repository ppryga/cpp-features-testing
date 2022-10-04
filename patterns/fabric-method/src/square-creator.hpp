#pragma once

#include <memory>
#include "shape.hpp"
#include "shape-creator.hpp"

class SquareCreator : public ShapeCreator {
public:
        virtual std::unique_ptr<Shape> GetShape();
};
