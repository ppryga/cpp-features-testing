#pragma once

/* The goal of this sample is to show consequences of use a flag to mark a class instance as not constructed completely
 * in case of constructor failure. In the example failure is implemented in a BaseSetFlag class constructor.
 *
 * Implications of the design:
 * - Objects of a BaseSetFlag and derived classes are instantiated but they are not completely constructed..
 * - Handling of the situation is delegated to user, that may cause errors e.g. forgotten check after object creation.
 * - In case of more complicated classes construction may fail during e.g. copying, that may be hard to verify or
 *   ould introduce lot of additional unnecessary code, increase mainternance cost.
 * - To prevent issues caused by call of a methog on not completely created object, every method may check whether it
 *   is called on completely created object. That introduces more maintenance and creates next complications e.g.
 *   getter method that returns int value where all values are valid.
 *
 * The only thing that in certain conditions may be seen as advantage of this method is lack of exceptions.
 */
#include <stdexcept>

class BaseSetFlag {
protected:
        int m_a;
        int m_b;
        int m_c;
        bool m_constructed; // Flag member that stores information whether object is constructed successfully
public:
        BaseSetFlag() = default;
        explicit BaseSetFlag(int a);

        int GetA() const;

        bool IsConstructed();
};

void test_construction_base_set_flag();
