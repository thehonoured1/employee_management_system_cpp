#include "ProduceManager.h"

ProduceManager::ProduceManager(int id, const std::string& name)
    : Employee(id, name) {
    this->department = "Produce";
    this->position = "Produce Manager";
    this->fixedSalary = 5000.0;
    this->hourlyRate = 0;
}

double ProduceManager::calculateSalary() const {
    return this->fixedSalary;
}