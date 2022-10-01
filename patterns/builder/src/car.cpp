#include <ostream>

#include "car.hpp"

std::ostream& operator<< (std::ostream& Os, EngineType Type) {
        switch(Type) {
        case EngineType::ENGINE_DIESEL:
                        return Os << "Diesel";
        case EngineType::ENGINE_PETROL:
                        return Os << std::string("Petrol");
        case EngineType::ENGINE_PLUG_IN_HYBRID:
                        return Os << std::string("Hybrid");
        case EngineType::ENGINE_ELECTRIC:
                        return Os << std::string("Electric");
        }
}

std::ostream& operator<< (std::ostream& Os, BreaksType Type) {
        switch(Type) {
        case BreaksType::BREAK_DISC_STEEL_FULL:
                        return Os << std::string("Steel disc breaks");
        case BreaksType::BREAK_DISC_STEEL_VENTILATED:
                        return Os << std::string("Steel ventilated disc breaks");
        case BreaksType::BREAK_DISC_CARBON:
                        return Os << std::string("Carbon disc breaks");
        case BreaksType::BREAK_DRUM:
                        return Os << std::string("Drum breaks");
        }

        return Os << static_cast<char>(Type);
}

std::string Car::GetName() const
{
        return m_Name;
}

void Car::SetName(std::string Name)
{
        m_Name = Name;
}

EngineType Car::GetEngineType() const
{
        return m_EngineType;
}

void Car::SetEngineType(EngineType Type)
{
        m_EngineType = Type;
}

float Car::GetEngineSize() const
{
        return m_EngineSize;
}

void Car::SetEngineSize(float SizeCm3)
{
        m_EngineSize = SizeCm3;
}

float Car::GetWheelSize() const
{
        m_WheelSize;
}

void Car::SetWheelSize(float SizeInch)
{
        m_WheelSize = SizeInch;
}

uint8_t Car::GetAirBagCount() const
{
        return m_AirBagCount;
}

void Car::SetAirBagCount(uint8_t Count)
{
        m_AirBagCount = Count;
}

BreaksType Car::GetFrontBreaksType() const
{
        return m_FrontBreaks;
}

void Car::SetFrontBreaksType(BreaksType Type)
{
        m_FrontBreaks = Type;
}

BreaksType Car::GetRearBreaksType() const
{
        return m_RearBreaks;
}

void Car::SetRearBreaksType(BreaksType Type)
{
        m_RearBreaks = Type;
}

std::vector<std::string> Car::GetPassengerComfortFeatures() const
{
        return m_ComfortFeatures;
}

void Car::AddPassengerComfortFeture(std::string Feature)
{
        m_ComfortFeatures.push_back(Feature);
}
