#include <iostream>
#include <stdexcept>
#include "throwing-constructor.hpp"

BaseThrow::BaseThrow(int a) : m_a{a} {
        /* For some reason the constuctor throws exception, hence at the end of a BaseThrow constructor call
         * the objects is not constructed completely and may not be used.
         */
        throw std::runtime_error("I failed but don't know why!");
}

Derived::Derived(int b, int c, int d) : BaseThrow(b), m_b(b), m_c(c), m_d(d) {
        std::cout << "Construction of this class does'n take care about exeptions." << std::endl;
        std::cout << "Possible exceptions must be handled by caller of the constructor." << std::endl;
}

DerivedCatch::DerivedCatch(int b, int c, int d) try : BaseThrow(b), m_b(b), m_c(c), m_d(d)
{
        std::cout<< "There were no exception when call to base class constructors or other memmbers on initialization \
                     list" << std::endl;
} catch (std::exception &except) {
        std::cout << "We have an exception, here is a reason: " << except.what() << std::endl;
        std::cout << "It is not end, I'll be implicitly re-thrown" << std::endl;
}

void test_construction_of_throwing() {

        try {
                /* Even though the constructo caught an exception thrown by base class constructore, the caller
                 * should also be careful about possible exceptions. Exception from constructors may never by swallowed
                 * by function-try block. I could make ilusion of sucessfully constructed object.
                 */
                DerivedCatch except_but_no_throw(1,2,3);

                Derived exept_catch_delegated(1,2,3);
        } catch (std::exception &except) {
                std::cout << "There was an exception but it was caught, why: " << std::endl;
                std::cout << except.what() << std::endl;
        }
}