#include <iostream>
#include "Menu.h"
#include "Employee.h"
#include "EmployeeRecord.h"
#include "SalesManager.h"//this is to declare an initial employee for testing purposes.
#include "Cashier.h" //this is to declare an initial employee for testing purposes.
using namespace std;

int main() {
	//valid login credentials:
	string validUsername = "admin";
	int validPassword = 123456;

	cout << "---Welcome to the GreenGrocery Simple Employee Management System!---\n\n";
	//Login
	cout << "Please Login with your Username: ";
	string username;
	cin >> username;
	if (username != validUsername) {
		cout << "Invalid Username. Exiting program." << endl;
		return 0;
	}
	cout << "Please enter your password: ";
	int password;
	cin >> password;
	if (password != validPassword) {
		cout << "Invalid password. Exiting program." << endl;
		return 0;
	}
	cout << "Login successful, opening menu.\n\n";

	//create and push initial object pointers to the vector.
	EmployeeRecord::employees.push_back(make_unique<Cashier>(2, "Kaizaki"));
	EmployeeRecord::employees.push_back(make_unique<SalesManager>(66, "Spamton G. Spamton"));
	Menu::displayMenu();
	return 0;
}