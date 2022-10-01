#include "tesla-builder.hpp"

bool TeslaBuilder::AddEngine()
{
        if (m_CarInstance) {
                m_CarInstance->SetEngineType(EngineType::ENGINE_ELECTRIC);
                m_CarInstance->SetEngineSize(0); // No combustion engine
        }

        return true;
}
bool TeslaBuilder::AddWheels()
{
        if (m_CarInstance)
        {
                m_CarInstance->SetWheelSize(18.0);
        }

        return true;
}
bool TeslaBuilder::AddAirBags()
{
        if (m_CarInstance)
        {
                m_CarInstance->SetAirBagCount(8);
        }

        return true;
}

bool TeslaBuilder::AddBreaks()
{
        if (m_CarInstance)
        {
                m_CarInstance->SetFrontBreaksType(BreaksType::BREAK_DISC_STEEL_FULL);
                m_CarInstance->SetRearBreaksType(BreaksType::BREAK_DISC_STEEL_FULL);
        }

        return true;
}

bool TeslaBuilder::AddPassengerComfortFeatures()
{
        if (m_CarInstance)
        {
                m_CarInstance->AddPassengerComfortFeture("Autonomous driving");
                m_CarInstance->AddPassengerComfortFeture("Four zone air-conditioninig");
                m_CarInstance->AddPassengerComfortFeture("Parkin assistance");
                m_CarInstance->AddPassengerComfortFeture("360deg view");
                m_CarInstance->AddPassengerComfortFeture("Head-up display");
                m_CarInstance->AddPassengerComfortFeture("Extra battery");
        }

        return true;
}
