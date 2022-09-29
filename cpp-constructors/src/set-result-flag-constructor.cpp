#include <iostream>
#include "set-result-flag-constructor.hpp"

BaseSetFlag::BaseSetFlag(int a) {
        /* m_a member is not set a value, hence stores some default initialized value. */
        m_constructed = false;
}

int BaseSetFlag::GetA() const {
        /* Always check if an object is constructed. This has implications, what to return in case of getter
                * method where every e.g. int value is valid. The best option is to throw exception... because this
                * call should not happen.
                */
        if (m_constructed) {
                return m_a;
        } else {
                return m_a; // Use zero just to make compiler satisying.
        }
        return m_a;
}

bool BaseSetFlag::IsConstructed() {
        return m_constructed;
}

int add(BaseSetFlag val_1, int val_2)
{
    return val_1.GetA() + val_2;
}


void test_construction_base_set_flag()
{
        /* polute the stack */
        int result_a = add(BaseSetFlag{30},30);

        result_a = add(BaseSetFlag{10},20);
        std::cout << "Invalid resuls due to constructor failure Add(BaseNoThrow{10}, 20) result: " << result_a;
        std::cout << std::endl;

        BaseSetFlag instance{10};

        if (instance.IsConstructed()) {
                result_a = add(instance, 50);
                std::cout << "Invalid resuls due to constructor failure Add(BaseNoThrow{10}, 50) result: " << result_a;
        } else {
                std::cout << "BaseSetFlag object was not constructed completely" << std::endl;
        }
}
