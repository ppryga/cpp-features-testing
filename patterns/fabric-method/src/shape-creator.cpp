#include "shape-creator.hpp"
#include "circle.hpp"

std::unique_ptr<Shape> ShapeCreator::GetShape() {
        // This is a default implementation of a methot to provide shape instances
        return std::move(std::make_unique<Circle>());
}