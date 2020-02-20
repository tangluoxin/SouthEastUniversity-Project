#include<iostream>
#include"Employee.h"
using namespace std;
Employee::Employee(const string &first, const string &last, const string &ssn,Date &c)
	:firstName(first), lastName(last), socialSecurityNumber(ssn),birthDate(c){}
void Employee::setFirstName(const string &first) { 
	firstName = first; 
}
string Employee::getFirstName()const {
	return firstName;
}
void Employee::setLastName(const string &last) {
	lastName = last; 
}
string Employee::getLastName()const { 
	return lastName; 
}
void Employee::setSocialSecurityNumber(const string &ssn) { 
	socialSecurityNumber = ssn; 
}
string Employee::getSocialSecurityNumber()const { 
	return socialSecurityNumber;
}
void Employee::setBirthDay(Date &c) { 
	birthDate = c;
}
Date Employee::getBirthDay()const {
	return birthDate; 
}
void Employee::print() {
	cout << getFirstName() << " " << getLastName() << "birthday: "
		<< getBirthDay() << "social security number: " << getSocialSecurityNumber();
}
double Employee::earnings(){}