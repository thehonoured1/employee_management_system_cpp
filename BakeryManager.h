#pragma once
#include "Employee.h"

class BakeryManager : public Employee {
public:
    BakeryManager(int id, const std::string& name);
    double calculateSalary() const override;
};