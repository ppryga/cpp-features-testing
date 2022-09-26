#pragma once

/* This is an example of very basic inheritance tree and constructors implementation.
 * The goal is to show all possible use cases for construction of a class.
 *
 * TODO: Add missing use cases.
 */
#include <stdexcept>

class BaseThrow {
protected:
        int m_a;
public:
        BaseThrow() = default;
        explicit BaseThrow(int a);

        int GetA() {
                return m_a;
        }
};

class Derived : public BaseThrow {
private:
        int m_b;
        int m_c;
        int m_d;
public:
        Derived(int b, int c, int d);
};

class DerivedCatch : public BaseThrow {
private:
        int m_b;
        int m_c;
        int m_d;
public:
        DerivedCatch(int b, int c, int d);
};

void test_construction_of_throwing();
