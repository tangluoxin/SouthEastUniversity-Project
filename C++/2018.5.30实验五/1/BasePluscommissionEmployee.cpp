#include<iostream>
#include"BasePluscommissionEmployee.h"
using namespace std;
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last, const string &ssn, Date &c, double sales, double rate, double salary)
	:CommissionEmployee(first, last, ssn, c, sales, rate) {
	setBaseSalary(salary);
}
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
	if (salary >= 0.0) {
		baseSalary = salary; 
	}
	else { 
		throw invalid_argument("Salary must be >= 0.0"); 
	}
}
double BasePlusCommissionEmployee::getBaseSalary()const { 
	return baseSalary;
}
double BasePlusCommissionEmployee::earnings()const {
	double a = 0;
	a= getBaseSalary() + CommissionEmployee::earnings()
	return a;
}
void BasePlusCommissionEmployee::print()const {
	cout << "base-salaried ";
	CommissionEmployee::print();
	cout << "   base salary: " << getBaseSalary();
}