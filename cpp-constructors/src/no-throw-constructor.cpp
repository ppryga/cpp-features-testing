#include <iostream>
#include <no-throw-constructor.hpp>

BaseNoThrow::BaseNoThrow(float f) : m_f{f}, m_a{0} {}

int BaseNoThrow::GetA() const {
        return m_a;
}

float BaseNoThrow::GetF() const {
        return m_f;
}

DerivedNoThrow::DerivedNoThrow(int b, int c, int d) : BaseNoThrow(b), m_b(b), m_c(c), m_d(d) {}

int add(BaseNoThrow a, int value) {
    return a.GetA() + value;
}

float add(BaseNoThrow val_1, float val_2)
{
    return val_1.GetF() + val_2;
}

void test_construction_of_no_throw() {

        int result_a = add(BaseNoThrow{1},2);
        std::cout << "Add(BaseNoThrow{1}, 2) result: " << result_a << std::endl;

        float resulf_f = add(3.3f, 4.6f);
        std::cout << "Add(3.3f, 4.6f) result " << resulf_f << std::endl;

        resulf_f = add(BaseNoThrow{4.3f}, 5.6f);
        std::cout << "Add(BaseNoThrow{4.3f}, 5.6f) result " << resulf_f << std::endl;

        /* DerivedNoThrow is a LiteralType, it has got a constexpr constructor. Its objects may be used in 
         * constexpr statements.
         */
        constexpr auto x = DerivedNoThrow(1,2,3,4).GetSum() + 100;
        //static_assert(x < 100); // uncomment to make sure the x variable is computed at compile time
}
