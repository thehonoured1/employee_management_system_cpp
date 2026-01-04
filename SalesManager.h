#pragma once
#include "Employee.h"

class SalesManager : public Employee {
public:
    SalesManager(int id, const std::string& name);
    double calculateSalary() const override;
};