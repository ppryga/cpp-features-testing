#include <iostream>
#include "static-method-constructor.hpp"

std::optional<BaseStaticCreate> BaseStaticCreate::GetInstance(int A, bool FailConstruction)
{
        if (FailConstruction == true) {
                return std::nullopt;
        } else {
                return BaseStaticCreate{A};
        }
}

BaseStaticCreate::BaseStaticCreate(int A) : m_a(A) { }

int BaseStaticCreate::GetA() const
{
        return m_a;
}

void test_construction_base_static_create()
{
        auto instance = BaseStaticCreate::GetInstance(34);

        if (instance) {
                std::cout << "Instance created and this is my A value: " << instance->GetA() << std::endl;
        }

        instance = BaseStaticCreate::GetInstance(22, true);

        if (!instance) {
                std::cout << "Instance creation failed" << std::endl;
        }
}