#pragma once

#include <iostream>
#include "shape.hpp"

class Circle : public Shape {
public:
        Circle() : Shape("Circle") {}

        void DrawShape() override {
                std::cout << "I'm circle" << std::endl;
        }
};