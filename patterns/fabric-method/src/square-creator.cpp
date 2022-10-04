#include <memory>

#include "square-creator.hpp"
#include "square.hpp"

std::unique_ptr<Shape> SquareCreator::GetShape() {
        // This is a default implementation of a methot to provide shape instances
        return std::move(std::make_unique<Square>());
}