#pragma once
#include <string>

class Employee {
protected:
    int employeeID;
    std::string name;
    std::string department;
    std::string position;
    double hoursWorked;
    double hourlyRate;
    double fixedSalary;

public:
    //constructors
    Employee();
    Employee(int id, const std::string& name);
    //For reference, constructor below:
    /*Employee::Employee(int id, const std::string& name)
    : employeeID(id), name(name), department("N/A"), position("N/A"),
      hoursWorked(0.0), hourlyRate(0.0), fixedSalary(0.0) {}
*/

    // Virtual destructor for polymorphism.
    virtual ~Employee() = default;

    // getters
    int getID() const;
    std::string getName() const;
    std::string getDepartment() const;
    std::string getPosition() const;
    double getHoursWorked() const;
    double getHourlyRate() const;
    double getFixedSalary() const;

    // setters     // Setters for department, position, and rates are not needed, because they are defined in the derived classes.
    void setID(int id);
    void setName(const std::string& name);
    void setHourlyRate(double rate);
    void setFixedSalary(double salary);

    void addHoursWorked(double hours); 
 

    //virtual= optional override methods permitted in subclasses.
    virtual double calculateSalary() const;
    virtual void display() const;
    static void printTableHeader();
};