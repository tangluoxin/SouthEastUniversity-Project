#ifndef DATE
#define DATE
#include<iostream>
#include<string>
using namespace std;
class Date {
	friend ostream &operator << (ostream &out, Date &c);
public:
	Date();
	Date(int, int, int);
	Date operator = (Date &c);
private:
	int year;
	string month;
	int day;
};
#endif