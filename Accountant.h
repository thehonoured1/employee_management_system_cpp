#pragma once
#include "Employee.h"

class Accountant : public Employee {
public:
    Accountant(int id, const std::string& name);
    double calculateSalary() const override;
};