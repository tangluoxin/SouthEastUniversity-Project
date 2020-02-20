#ifndef HOURLY_H
#define HOURLY_H
#include"Employee.h"
#include<iostream>
using namespace std;
class HourlyEmployee :public Employee {
public:
	HourlyEmployee(const string &first, const string &last, const string &ssn, Date &c, double wage= 0.0, double hour= 0.0);
	void setHourlyWage(double);
	double getHourlyWage()const;
	void setHoursWorked(double);
	double getHoursWorked()const;
	virtual double earnings()const;
	virtual void print()const;
private:
	double hourlyWage;
	double hoursWorked;
};
#endif