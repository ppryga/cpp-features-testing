#pragma once

/* This is an example of very basic inheritance tree and constructors implementation.
 * The goal is to show all possible use cases for construction of a class.
 *
 * TODO: Add missing use cases.
 */

class BaseNoThrow {
public:
        BaseNoThrow() = default;
        /* Make explicit to make it non-converting constructor. Constexpr construction is by default inline, hence 
         * mubst be declared in a class declaration file.
         */
        constexpr explicit BaseNoThrow(int a) : m_a{a}, m_f{0.0} {}

        /* This constructor is convertible, see use of it in a function call */
        BaseNoThrow(float b);

        int GetA() const;
        float GetF() const;

protected:
        int m_a;
        float m_f;
};

class DerivedNoThrow : public BaseNoThrow {
public:
        DerivedNoThrow(int b, int c, int d);

        constexpr DerivedNoThrow(int a, int b, int c, int d) : BaseNoThrow(a), m_b(b), m_c(c), m_d(d) {}

        constexpr int GetSum() {
                return m_a + m_b + m_c + m_d;
        }
private:
        int m_b;
        int m_c;
        int m_d;
};

void test_construction_of_no_throw();