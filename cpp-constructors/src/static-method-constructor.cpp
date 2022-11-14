#include <iostream>
#include "static-method-constructor.hpp"

std::optional<BaseStaticCreate> BaseStaticCreate::GetInstance(int A, bool FailConstruction)
{
        if (FailConstruction == true) {
                return std::nullopt;
        } else {
                return std::move(BaseStaticCreate{A});
        }
}

BaseStaticCreate::BaseStaticCreate(int A) : m_a(A)
{
        std::cout << "regular constructor" << std::endl;
}

BaseStaticCreate::~BaseStaticCreate()
{
        std::cout << "destructor" << std::endl;
}

int BaseStaticCreate::GetA() const
{
        return m_a;
}

BaseStaticCreate::BaseStaticCreate(const BaseStaticCreate&)
{
        std::cout << "copy constructor" << std::endl;
}

BaseStaticCreate::BaseStaticCreate(BaseStaticCreate&& other)
{
        std::cout << "move constructor" << std::endl;
        this->m_a = other.m_a;
        other.m_a = 0xFF;
}

BaseStaticCreate& BaseStaticCreate::operator=(BaseStaticCreate&& other)
{
        std::cout << "move assignment" << std::endl;

        this->m_a = other.m_a;

        return *this;
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