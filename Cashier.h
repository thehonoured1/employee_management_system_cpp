#pragma once
#include "Employee.h"

class Cashier : public Employee {
public:
    Cashier(int id, const std::string& name);
};