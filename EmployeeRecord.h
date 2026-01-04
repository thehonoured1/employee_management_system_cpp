#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Employee.h"
using namespace std;

class EmployeeRecord
{
public:
	static vector<unique_ptr<Employee>> employees; //stores smart pointers to employee objects

	//add an employee to the vector.
	static void addEmployee(); //ask for dept and position to determine subclass to-be-created.
	static void editEmployee();
	static Employee* searchEmployee();
	static Employee* searchEmployee( int ID);
	static void displayEmployee();
	static void displayEmployee(int ID);
	static void deleteEmployee();
	static int get_integer_input();
	static double get_double_input();
	
};

