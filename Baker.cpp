#include "Baker.h"

Baker::Baker(int id, const std::string& name)
    : Employee(id, name) {
    this->department = "Bakery";
    this->position = "Baker";
    this->hourlyRate = 18.00;
    this->fixedSalary = 0;
}