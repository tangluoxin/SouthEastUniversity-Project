#include<iostream>
#include"HourlyEmployee.h"
using namespace std;
HourlyEmployee::HourlyEmployee(const string &first, const string &last, const string &ssn, Date &c, double wage, double hour)
	:Employee(first, last, ssn, c) {
	setHourlyWage(wage);
	setHoursWorked(hour);
}
void HourlyEmployee::setHourlyWage(double wage) {
	hourlyWage = wage;
}
double HourlyEmployee::getHourlyWage()const {
	return hourlyWage;
}
void HourlyEmployee::setHoursWorked(double hour) {
	hoursWorked = hour;
}
double HourlyEmployee::getHoursWorked()const {
	return hoursWorked;
}
double HourlyEmployee::earnings()const {
	double a = 0;
	a = getHourlyWage()*getHoursWorked()
		return a;
}
void HourlyEmployee::print()const {
	cout << "hourly employee: " << endl;
	Employee::print();
	cout << "hourly wage: " << getHourlyWage();
	cout << " hours worked: " << getHoursWorked();
}
