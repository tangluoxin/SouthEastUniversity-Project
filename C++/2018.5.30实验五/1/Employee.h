#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
using namespace std;
#include"Date.h"
class Employee {
public:
	Employee(const string &, const string &, const string &, Date &);
	void setFirstName(const string &);
	string getFirstName()const;
	void setLastName(const string &);
	string getLastName()const;
	void setSocialSecurityNumber(const string &);
	string getSocialSecurityNumber()const;
	void setBirthDay(Date &);
	Date getBirthDay()const;
	virtual double earnings();
	virtual void print();
private:
	string firstName;
	string lastName;
	string socialSecurityNumber;
	Date birthDate;
};
#endif
