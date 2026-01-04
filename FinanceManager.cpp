#include "FinanceManager.h"

FinanceManager::FinanceManager(int id, const std::string& name)
    : Employee(id, name) {
    this->department = "Business Finance";
    this->position = "Finance Manager";
    this->fixedSalary = 6500.0;
    this->hourlyRate = 0;
}

double FinanceManager::calculateSalary() const {
    return this->fixedSalary;
}