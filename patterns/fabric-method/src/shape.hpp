#pragma once

#include <string>

class Shape {
public:
        Shape(std::string Name) : m_Name(Name) {}
        virtual ~Shape() = default;

        virtual void DrawShape() = 0;
        virtual std::string GetName() {
                return m_Name;
        }
protected:
        std::string m_Name;
};
