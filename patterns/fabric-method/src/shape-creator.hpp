#pragma once

#include <memory>
#include "shape.hpp"

class ShapeCreator {
public:
        virtual std::unique_ptr<Shape> GetShape();
};
