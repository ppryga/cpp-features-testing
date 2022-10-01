#pragma once

#include <string>
#include <memory>

#include "car.hpp"
#include "car-builder.hpp"

class BmwBuilder : public CarBuilder {
public:
        BmwBuilder() = default;
        ~BmwBuilder() = default;

        virtual bool AddEngine();
        virtual bool AddWheels();
        virtual bool AddAirBags();
        virtual bool AddBreaks();
        virtual bool AddPassengerComfortFeatures();
};
