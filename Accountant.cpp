#include "Accountant.h"

Accountant::Accountant(int id, const std::string& name)
    : Employee(id, name) {
    this->department = "Business Finance";
    this->position = "Accountant";
    this->fixedSalary = 4800.0;
    this->hourlyRate = 0;
}

double Accountant::calculateSalary() const {
    return this->fixedSalary;
}