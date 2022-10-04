#include <iostream>

#include "shape-creator.hpp"
#include "square-creator.hpp"

void app_main(ShapeCreator& Creator) {

    auto shape = Creator.GetShape();
    std::cout << "Shape name is: " << shape->GetName() << std::endl;
    std::cout << "Draw: ";
    shape->DrawShape();
    std::cout << std::endl;
}

int main(int, char**) {
    std::cout << "Test factory method\n!" << std::endl;

    /* Let assume the main function is an environment where the "app_main" is instantiated and executed.
     * The app_main may be executed with different implementations of ShapeCreator that provide varied shapes.
     * the app_main is separated from the paricular implementation of shape, it is not affected by internal changes 
     * to shape implementation as well as extension of shapes inheritance family. Implementor of a shape may add/remove
     * shapes and app_main is unafected by this. Only valid ShapeCreator has to be provided to the app_main to make
     * it working.
     */

    auto defaultCreator = ShapeCreator();
    app_main(defaultCreator);

    auto squareCreator = SquareCreator();
    app_main(squareCreator);
}
