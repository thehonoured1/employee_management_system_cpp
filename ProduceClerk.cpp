#include "ProduceClerk.h"

ProduceClerk::ProduceClerk(int id, const std::string& name)
    : Employee(id, name) {
    this->department = "Produce";
    this->position = "Produce Clerk";
    this->hourlyRate = 15.50;
    this->fixedSalary = 0;
}