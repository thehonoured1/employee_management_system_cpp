#pragma once
#include "Employee.h"

class ProduceManager : public Employee {
public:
    ProduceManager(int id, const std::string& name);
    double calculateSalary() const override; // Переопределяем метод
};