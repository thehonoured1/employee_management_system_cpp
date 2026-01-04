#pragma once
#include "Employee.h"

class FinanceManager : public Employee {
public:
    FinanceManager(int id, const std::string& name);
    double calculateSalary() const override;
};