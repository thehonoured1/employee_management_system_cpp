#include "SalesManager.h"

SalesManager::SalesManager(int id, const std::string& name)
    : Employee(id, name) {
    this->department = "Sales";
    this->position = "Sales Manager";
    this->fixedSalary = 5500.0;
    this->hourlyRate = 0;
}

double SalesManager::calculateSalary() const {
    return this->fixedSalary;
}