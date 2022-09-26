#include <iostream>
#include "no-throw-constructor.hpp"
#include "throwing-constructor.hpp"

int main(int, char**) {
    std::cout << "Tests started!" << std::endl;

    test_construction_of_no_throw();
    test_construction_of_throwing();
}
