#include "Menu.h"
#include "EmployeeRecord.h"
#include <iostream>

using namespace std;

void Menu::displayMenu() {
	
	while (true) {
		cout << "\n\n ===== GreenGrocery SEMS Menu =====\n";
		cout << "1. Add Employee\n";
		cout << "2. Display All Employees\n";
		cout << "3. Search and display Employee by ID\n";
		cout << "4. Edit Employee\n";
		cout << "5. Delete Employee\n";
		cout << "6. Exit\n";
		cout << "========================================\n";
		cout << "Select an option (1-6): ";
		int selection = EmployeeRecord::get_integer_input();
		cout << endl;
		switch (selection)
		{
			case 1:
				EmployeeRecord::addEmployee();
				break;
			case 2:
				EmployeeRecord::displayEmployee();
				break;
			case 3: 
				cout << "Enter Employee ID to search: ";
				int ID;
				ID = EmployeeRecord::get_integer_input();
				EmployeeRecord::displayEmployee(ID);
				break;

			case 4:
				EmployeeRecord::editEmployee();
				break;
			case 5:
				EmployeeRecord::deleteEmployee();
				break;
			case 6:
				cout << "Exiting system. Goodbye!\n";
				return;
			default:
				cout << "Invalid choice. Please select a valid option (1-6).\n";
				break;
		}
	}
}