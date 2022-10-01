#pragma once

#include <string>
#include <memory>

#include "car.hpp"
#include "car-builder.hpp"

class TeslaBuilder : public CarBuilder {
public:
        TeslaBuilder() = default;
        ~TeslaBuilder() = default;

        virtual bool AddEngine();
        virtual bool AddWheels();
        virtual bool AddAirBags();
        virtual bool AddBreaks();
        virtual bool AddPassengerComfortFeatures();
};
