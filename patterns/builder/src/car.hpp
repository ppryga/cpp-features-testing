#pragma once
#include <string>
#include <vector>

enum class EngineType : uint8_t {
        ENGINE_DIESEL,
        ENGINE_PETROL,
        ENGINE_PLUG_IN_HYBRID,
        ENGINE_ELECTRIC
};

enum class BreaksType : uint8_t {
        BREAK_DISC_STEEL_FULL,
        BREAK_DISC_STEEL_VENTILATED,
        BREAK_DISC_CARBON,
        BREAK_DRUM,
};

std::ostream& operator<< (std::ostream& Os, EngineType Type);
std::ostream& operator<< (std::ostream& Os, BreaksType Type);

class Car {
public:
        Car() = default;
        ~Car() = default;

        std::string GetName() const;
        void SetName(std::string Name);

        EngineType GetEngineType() const;
        void SetEngineType(EngineType Type);

        /* For non-combustion engines returns 0.0f, for combustion engines returns its capacity in [cm3] */
        float GetEngineSize() const;
        void SetEngineSize(float size_cm3);

        float GetWheelSize() const;
        void SetWheelSize(float size_inch);

        uint8_t GetAirBagCount() const;
        void SetAirBagCount(uint8_t);

        BreaksType GetFrontBreaksType() const;
        void SetFrontBreaksType(BreaksType Type);

        BreaksType GetRearBreaksType() const;
        void SetRearBreaksType(BreaksType Type);
 
        std::vector<std::string> GetPassengerComfortFeatures() const;
        void AddPassengerComfortFeture(std::string Feature);
private:
        std::string m_Name;
        EngineType m_EngineType;
        float m_EngineSize;
        float m_WheelSize;
        uint8_t m_AirBagCount;
        BreaksType m_FrontBreaks;
        BreaksType m_RearBreaks;
        std::vector<std::string> m_ComfortFeatures;
};