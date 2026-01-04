#include "Cashier.h"

Cashier::Cashier(int id, const std::string& name)
    : Employee(id, name) {
    this->department = "Sales";
    this->position = "Cashier";
    this->hourlyRate = 14.00;
    this->fixedSalary = 0;
}