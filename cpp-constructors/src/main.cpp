#include <iostream>
#include "no-throw-constructor.hpp"
#include "throwing-constructor.hpp"
#include "set-result-flag-constructor.hpp"

int main(int, char**) {
    std::cout << "Tests started!" << std::endl;

    test_construction_of_no_throw();
    test_construction_of_throwing();
    test_construction_base_set_flag();
}
