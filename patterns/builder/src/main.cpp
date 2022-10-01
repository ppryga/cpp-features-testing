#include <iostream>

#include "car.hpp"
#include "car-builder.hpp"
#include "bmw-builder.hpp"
#include "tesla-builder.hpp"

bool car_assembly(CarBuilder &Builder)
{
    if (!Builder.PrepareInstance()) {
        return false;
    }

    if (!Builder.AddEngine()) {
        return false;
    }

    if (!Builder.AddAirBags()) {
        return false;
    }

    if (!Builder.AddWheels()) {
        return false;
    }

    if (!Builder.AddAirBags()) {
        return false;
    }

    if (!Builder.AddBreaks()) {
        return false;
    }

    if (!Builder.AddPassengerComfortFeatures()) {
        return false;
    }

    return true;
}

void print_car_setup(const Car &Instance) {
    std::cout << "Car details:" << std::endl;
    std::cout << "\t - Name: " << Instance.GetName() << std::endl;
    std::cout << "\t - Engine type: " << Instance.GetEngineType() << std::endl;
    std::cout << "\t - Engine size: " << Instance.GetEngineSize() << std::endl;
    std::cout << "\t - Wheels size: " << Instance.GetWheelSize() << std::endl;
    std::cout << "\t - Front breaks:" << Instance.GetFrontBreaksType() << std::endl;
    std::cout << "\t - Rear breaks: " << Instance.GetRearBreaksType() << std::endl;
    std::cout << "\t - Airbags number" << Instance.GetAirBagCount() << std::endl;
    std::cout << "\t - Optional features:" << std::endl;
    for (auto feature : Instance.GetPassengerComfortFeatures()) {
        std::cout << "\t   * " << feature << std::endl;
    }
}

int main(int, char**) {
    std::cout << "Build BMW!" << std::endl;

    BmwBuilder bmwBuilder;
    if (!car_assembly(bmwBuilder)) {
        std::cout << "BMW car build error" << std::endl;
        return -1;
    }

    auto bmwCar = bmwBuilder.GetInstance();
    print_car_setup(*bmwCar);

    std::cout << "Build Tesla!" << std::endl;

    TeslaBuilder teslaBuilder;
    if (!car_assembly(teslaBuilder)) {
        std::cout << "Tesla car build error" << std::endl;
        return -1;
    }

    auto teslaCar = teslaBuilder.GetInstance();
    print_car_setup(*teslaCar);
}
