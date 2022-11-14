#pragma once

/* The goal of this sample is to show possible approach to instantiate a class with static method instead
 * of a constructor.
 *
 * To avoid use of heap and dynamic allocation static method returns std::optional<T>. Thanks to that the code allows:
 * - use stack to create a class instance
 * - return error by empty optional 
 * - in case of  
 */
#include <optional>

class BaseStaticCreate {
protected:
        int m_a;
        int m_b;
        int m_c;
        bool m_constructed; // Flag member that stores information whether object is constructed successfully
public:
        BaseStaticCreate() = default;
        explicit BaseStaticCreate(int a);
        BaseStaticCreate(const BaseStaticCreate&);
        BaseStaticCreate(BaseStaticCreate&&);
        BaseStaticCreate& operator=(BaseStaticCreate&& other);

        ~BaseStaticCreate();
public:
        static std::optional<BaseStaticCreate> GetInstance(int A, bool failConstruction = false);

        int GetA() const;

};

void test_construction_base_static_create();
