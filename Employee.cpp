#include "Employee.h"
#include <iostream>
#include <iomanip> 
using namespace std;

// default constructor
Employee::Employee() 
    : employeeID(0), name("N/A"), department("N/A"), position("N/A"),
      hoursWorked(0.0), hourlyRate(0.0), fixedSalary(0.0) {}

// parameterized constructor, only includes ID and name. --This is not used in the program, only for reference.--
Employee::Employee(int id, const std::string& name)
    : employeeID(id), name(name), department("N/A"), position("N/A"),
      hoursWorked(0.0), hourlyRate(0.0), fixedSalary(0.0) {}

// getter implementations
int Employee::getID() const { return employeeID; }
string Employee::getName() const { return name; }
string Employee::getDepartment() const { return department; }
string Employee::getPosition() const { return position; }
double Employee::getHoursWorked() const { return hoursWorked; }
double Employee::getHourlyRate() const { return hourlyRate; }
double Employee::getFixedSalary() const { return fixedSalary; }

// setter implementations
void Employee::setID(int id) { this->employeeID = id; }
void Employee::setName(const string& name) { this->name = name; }
void Employee::setHourlyRate(double rate) { hourlyRate = rate; }
void Employee::setFixedSalary(double salary) { fixedSalary = salary; }

//add to total hours worked
void Employee::addHoursWorked(double hours) {
    this->hoursWorked += hours;
}

// virtual calculate salary method FOR HOURLY PAY, to be overridden by FULL TIME SALARY subclasses.
double Employee::calculateSalary() const {
    return hoursWorked * hourlyRate;
}

// --display employee data, and if fixed or hourly salary.

void Employee::display() const {
    cout << left
        << setw(5) << employeeID
        << setw(20) << name
        << setw(15) << department
        << setw(20) << position;
    //Display Fixed Salary if fixed salary is more than 0.
    if (fixedSalary > 0) {
        cout << setw(10) << "Fixed"
            << setw(15) << "-"
            << setw(15) << "-"
            << setw(20) << calculateSalary();
    }
    //Display Hourly Pay and Hours Worked if fixed salary is 0.
    else {
        cout << setw(10) << "Hourly"
            << setw(15) << hoursWorked
            << setw(15) << hourlyRate
            << setw(20) << calculateSalary();
    }

    cout << endl;
}

// Add this helper to print a nice header ONCE
void Employee::printTableHeader() {
    cout << string(120, '-') << endl;
    cout << left
        << setw(5) << "ID"
        << setw(20) << "Name"
        << setw(15) << "Department"
        << setw(20) << "Position"
        << setw(10) << "Type"
        << setw(15) << "HoursWorked"
        << setw(15) << "HourlyRate"
        << setw(20) << "Monthly Pay"
        << endl;

    cout << string(120, '-') << endl;
}

/*void Employee::display() const {
    std::cout << std::left << std::setw(5) << "ID: " << employeeID << std::endl;
    std::cout << std::left << std::setw(15) << "Name: " << name << std::endl;
    std::cout << std::left << std::setw(15) << "Department: " << department << std::endl;
    std::cout << std::left << std::setw(15) << "Position: " << position << std::endl;
    //If fixed salary is more than 0, it is displayed as fixed.
    if (fixedSalary > 0) {
        std::cout << std::left << std::setw(15) << "Salary Type: " << "Fixed" << std::endl;
        std::cout << std::left << std::setw(15) << "Total Salary Per Month: " << calculateSalary() << "\n" << std::endl;
    } 
    //Or else the pay is displayed as Hourly
    else {
        std::cout << std::left << std::setw(15) << "Salary Type: " << "Hourly" << std::endl;
        std::cout << std::left << std::setw(15) << "Hours Worked This Month: " << hoursWorked << std::endl;
        std::cout << std::left << std::setw(15) << "Hourly Rate: " << hourlyRate << std::endl;
        std::cout << std::left << std::setw(15) << "Total Pay This Month: " << calculateSalary() <<"\n" << std::endl;
    }
}*/