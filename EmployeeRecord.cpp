#include "EmployeeRecord.h"
#include "Employee.h"
#include "ProduceManager.h"
#include "ProduceClerk.h"
#include "FinanceManager.h"
#include "Accountant.h"
#include "BakeryManager.h"
#include "Baker.h"
#include "SalesManager.h"
#include "Cashier.h"

#include <string>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

vector<unique_ptr<Employee>> EmployeeRecord::employees;

void EmployeeRecord::addEmployee() {
	cout << "\n--- Add New Employee ---\n";
	cout << "Select Position:\n";
	cout << "1. Produce Manager\n2. Produce Clerk\n3. Finance Manager\n4. Accountant\n";
	cout << "5. Bakery Manager\n6. Baker\n7. Sales Manager\n8. Cashier\n";
	cout << "Enter position choice: ";
	int positionChoice = get_integer_input();
	//validate input
	if (positionChoice >=9  || positionChoice <=0) {
		cout << "Invalid choice. Returning to menu...\n";
		return;
	}
	cout << "Please input the Employee's ID: ";
	int id = get_integer_input();

	// Check if the ID already exists
	for (const auto& emp : employees) {
		if (emp->getID() == id) {
			cout << "Employee with ID " << id << " already exists. Returning to menu...";
			return;
		}
	}
	cout << "Please input the Employee's name: ";
	string name;
	getline(cin, name);

	// Check if the Name already exists
	for (const auto& emp : employees) {
		string empName = emp->getName();
		if (empName == name) {
			cout << "Employee with name " << name << " already exists. Returning to menu...";
			return;
		}
	}
	cout << "Check if all the details are correct. If they are, input '1' to proceed with the addition. If they are not, enter any number.\n";
	int validAddition;
	cin >> validAddition;
	if (validAddition != 1) {
		cout << "Addition terminated, returning to menu...\n";
		return;
	}

	//Create a new employee unique nullptr and object
	unique_ptr<Employee> newEmployee;
	switch (positionChoice) {
		//each line below transfers ownership of the make_unique pointer to the newEmployee pointer.
		//this is the purpose of make_unique.
		case 1: newEmployee = make_unique<ProduceManager>(id, name); break;
		case 2: newEmployee = make_unique<ProduceClerk>(id, name); break;
		case 3: newEmployee = make_unique<FinanceManager>(id, name); break;
		case 4: newEmployee = make_unique<Accountant>(id, name); break;
		case 5: newEmployee = make_unique<BakeryManager>(id, name); break;
		case 6: newEmployee = make_unique<Baker>(id, name); break;
		case 7: newEmployee = make_unique<SalesManager>(id, name); break;
		case 8: newEmployee = make_unique<Cashier>(id, name); break;
		default:
			cout << "Invalid choice. Employee not added.\n";
			return;
	}
	// Add the new employee to the vector
	employees.push_back(move(newEmployee));
}
void EmployeeRecord::editEmployee() {
	// Implementation for editing an employee's details
	cout << "Entering edit mode. \n";
	cout << "If the employee moves to a different department or position, please delete the employee and add a new one.\n";
	//raw pointer to Employee object.
	Employee* employee = searchEmployee();
	if (!employee) {
		cout << "Returning to menu.\n";
		return;
	}
	cout << "Which field would you like to edit? {1: Name, 2: Hourly Rate, 3: Salary, 4: Hours Worked} ";
	int choice;
	cin >> choice;
	switch (choice) {
		case 1: {
			cout << "Enter new name: ";
			string newName;
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush leftover newline from any cin
			getline(cin, newName);
			employee->setName(newName);
			cout << "Employee detail updated successfully!" << endl;
			break;
		}
		case 2: {
			if (employee->getHourlyRate() == 0) {
				cout << "This employee is paid a fixed salary. Please select a different option." << endl;
				break;
			}
			cout << "Enter new Hourly Rate: ";
			double newRate=get_double_input();
			employee->setHourlyRate(newRate);
			cout << "Employee detail updated successfully!" << endl;
			break;
		}
		case 3: {
			if (employee->getFixedSalary() == 0) {
				cout << "This employee is hourly paid. Please select a different option." << endl;
				break;
			}
			cout << "Enter new salary: ";
			double newSalary = get_double_input();;
			employee->setFixedSalary(newSalary);
			cout << "Employee detail updated successfully!" << endl;
			break;
		}
		case 4:
			if (employee->getHourlyRate() == 0) {
				cout << "This employee is paid a fixed salary. Please select a different option." << endl;
				break;
			}
			cout << "Enter the hours worked to add to the Total Hours Worked this month: ";
			int hoursWorkedAdd;
			cin >> hoursWorkedAdd;
			employee->addHoursWorked(hoursWorkedAdd);

		
		default:
			cout << "Invalid choice." << endl;
			break;
	}
}
Employee* EmployeeRecord::searchEmployee() {
	cout << "Enter the Employee ID: ";
	int ID = get_integer_input();
	for (auto& emp : employees) {
		if (emp->getID() == ID) {
			return emp.get(); //get raw pointer, cpp inbuilt fn
		}
	}
	cout << "Employee not found." << endl;
	return nullptr;
}
//overload if there is already an ID passed:
Employee* EmployeeRecord::searchEmployee(int ID) {
	for (auto& emp : employees) {
		if (emp->getID() == ID) {
			return emp.get(); //get raw pointer
		}
	}
	cout << "Employee not found." << endl;
	return nullptr;
}


void EmployeeRecord::displayEmployee() {
	// Implementation for displaying all employees in a table.
	cout << "Displaying all employees: \n";
	Employee::printTableHeader(); //table header
	for (auto& emp : employees) {
		emp->display();
	}
	cout << string(120, '-') << endl;
}
void EmployeeRecord::displayEmployee(int ID) {
	Employee* emp = EmployeeRecord::searchEmployee(ID);
	if (!emp) {
		cout << "Employee not found. Returning to menu...\n\n";
		return;
	}
	cout << "Displaying employee " << ID << ": \n";
	Employee::printTableHeader();
	emp->display();
	cout << string(120, '-') << endl;
}

void EmployeeRecord::deleteEmployee() {
	cout << "Enter the Employee ID to delete: ";
	int ID = get_integer_input();

	for (auto it = employees.begin(); it != employees.end(); ++it) {//it is an iterator pointer.
		if ((*it)->getID() == ID) {
			employees.erase(it); // Removes the unique_ptr, deletes Employee
			cout << "Employee deleted successfully." << endl;
			return;
		}
	}
	cout << "Employee not found." << endl;
}
int EmployeeRecord::get_integer_input() {
	int choice;
	while (!(cin >> choice)) {//validate input
		cout << "Invalid input. Please enter a number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear any leftover input.
	return choice;
}
double EmployeeRecord::get_double_input() {
	double choice;
	while (!(cin >> choice)) {//validate input
		cout << "Invalid input. Please enter a number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear any leftover input.
	return choice;
}
