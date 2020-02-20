#include<iostream>
#include<string>
#include"Date.h"
using namespace std;
string mon[13] = { " ","January","February","March","April","May","June","July","August","September","October","November","December" };
ostream &operator<<(ostream &output, Date &c) {
	output << c.month << "," << c.day << ", " << c.year;
	return output;
}
Date::Date() {
	year = 0;
	day = 0;
}
Date::Date(int m, int d, int y) {
	month = mon[m];
	day = d;
	year = y;
}
Date Date::operator=(Date &c) {
	month = c.month;
	day = c.day;
	year = c.year;
	return *this;
}