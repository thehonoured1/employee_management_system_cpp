#include "BakeryManager.h"

BakeryManager::BakeryManager(int id, const std::string& name)
    : Employee(id, name) {
    this->department = "Bakery";
    this->position = "Bakery Manager";
    this->fixedSalary = 4500.0;
    this->hourlyRate = 0;
}

double BakeryManager::calculateSalary() const {
    return this->fixedSalary;
}