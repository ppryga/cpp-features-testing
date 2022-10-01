#include "bmw-builder.hpp"

bool BmwBuilder::AddEngine()
{
        if (m_CarInstance) {
                m_CarInstance->SetEngineType(EngineType::ENGINE_DIESEL);
                m_CarInstance->SetEngineSize(3000); // 3.0L
        }

        return true;
}
bool BmwBuilder::AddWheels()
{
        if (m_CarInstance)
        {
                m_CarInstance->SetWheelSize(21.0);
        }

        return true;
}
bool BmwBuilder::AddAirBags()
{
        if (m_CarInstance)
        {
                m_CarInstance->SetAirBagCount(8);
        }

        return true;
}

bool BmwBuilder::AddBreaks()
{
        if (m_CarInstance)
        {
                m_CarInstance->SetFrontBreaksType(BreaksType::BREAK_DISC_CARBON);
                m_CarInstance->SetRearBreaksType(BreaksType::BREAK_DISC_CARBON);
        }

        return true;
}

bool BmwBuilder::AddPassengerComfortFeatures()
{
        if (m_CarInstance)
        {
                m_CarInstance->AddPassengerComfortFeture("Adaptive speed control");
                m_CarInstance->AddPassengerComfortFeture("Six zone air-conditioninig");
                m_CarInstance->AddPassengerComfortFeture("Parkin assistance");
                m_CarInstance->AddPassengerComfortFeture("360deg view");
                m_CarInstance->AddPassengerComfortFeture("Head-up display");
        }

        return true;
}
