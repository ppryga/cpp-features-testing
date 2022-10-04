#pragma once

#include <iostream>
#include "shape.hpp"

class Square : public Shape {
public:
        Square() : Shape("Square") {}

        void DrawShape() override {
                std::cout << "I'm square" << std::endl;
        }
};