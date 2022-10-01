#pragma once

#include <memory>
#include "car.hpp"

/* Pure abstract class (interface) with API to build a car object. */
class CarBuilder {
public:
        virtual ~CarBuilder() {
                if (m_CarInstance) {
                        m_CarInstance.reset();
                }
        }

        virtual bool AddEngine() = 0;
        virtual bool AddWheels() = 0;
        virtual bool AddAirBags() = 0;
        virtual bool AddBreaks() = 0;
        virtual bool AddPassengerComfortFeatures() = 0;

        virtual bool PrepareInstance() {
                if (m_CarInstance != NULL) {
                        return false;
                } else {
                        m_CarInstance = std::make_unique<Car>();
                }

                return true;
        }
        virtual std::unique_ptr<Car> GetInstance() {
                if (m_CarInstance)
                {
                        return std::move(m_CarInstance);
                } else {
                        return NULL;
                }
        }
protected:
        std::unique_ptr<Car> m_CarInstance;
};