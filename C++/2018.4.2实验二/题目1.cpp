#include<iostream>
#include <string>
#include <ctime>
using std::time;
using std::localtime;
using std::tm;
using std::time_t;
using std::string;
using namespace std;
class Date
{
public:
	//Date(); // default constructor uses <ctime> functions to set date
	Date(int, int, int); // constructor using dd/mm/yy format
	Date(int, int); // constructor using ddd yyyy format
	Date(int, string, int); // constructor using Month dd, yyyy format
	void print() const; // print date in month/day/year format
	void printDDDYYYY() const; // print date in ddd yyyy format
	void printMMDDYY() const; // print date in mm/dd/yy format
	void printMonthDDYYYY() const; // print date in Month dd, yyyy format
	~Date(); // provided to confirm destruction order
private:
	int month; // 1-12 (January-December)
	int day; // 1-31 based on month
	int year; // any year
};
/*Date::Date() {
struct tm *ptr;

time_t t = time(0);

ptr = localtime(&t);
day = ptr->tm_mday;
month = 1 + ptr->tm_mon;
year = ptr->tm_year + 1900;

}*/
Date::Date(int dd, int mm, int yy) {
	if (dd <= 31 && dd > 0&&mm!=2) { day = dd; }
	if (mm == 2 &&dd <= 28 && dd > 0) { day = dd; }
	if (mm <= 12 && mm > 0) { month = mm; }
	year = yy;
}
Date::Date(int ddd, int yyyy) {
	if (ddd <=31) { day = ddd, month = 1; }
	if (ddd > 31 && ddd <= 59) { day = ddd - 31, month = 2; }
	if (ddd > 59 && ddd <= 90) { day = ddd - 59, month = 3; }
	if (ddd > 90 && ddd <= 120) { day = ddd - 90, month = 4; }
	if (ddd > 120 && ddd <= 151) { day = ddd - 120, month = 5; }
	if (ddd > 151 && ddd <= 181) { day = ddd - 151, month = 6; }
	if (ddd > 181 && ddd <= 212) { day = ddd - 181, month = 7; }
	if (ddd > 212 && ddd <= 243) { day = ddd - 212, month = 8; }
	if (ddd > 243 && ddd <= 273) { day = ddd - 243, month = 9; }
	if (ddd > 273 && ddd <= 304) { day = ddd - 273, month = 10; }
	if (ddd > 304 && ddd <= 334) { day = ddd - 304, month = 11; }
	if (ddd > 334 && ddd <= 356) { day = ddd - 334, month = 12; }
	if (ddd > 356) { cout << "输入不合法"; }
	year = yyyy;
}
Date::Date( int dd, string Mon, int yyyy) {
	string s = Mon;
	for (auto &c : s)
		c = towupper(c);
	if (dd <= 31 &&dd > 0 && s != "FEBRUARY") { day = dd; }
	if (s== "FEBRUARY"&&dd <= 28 && dd > 0) { day = dd; }
	year = yyyy;
	if (s == "JANUARY") { month = 1; }
	if (s == "FEBRUARY") { month = 2; }
	if (s == "MARCH") { month = 3; }
	if (s == "APRIL") { month = 4; }
	if (s == "MAY") { month = 5; }
	if (s == "JUNE") { month = 6; }
	if (s == "JULY") { month = 7; }
	if (s == "AUGUST") { month = 8; }
	if (s == "SEPTEMBER") { month = 9; }
	if (s == "OCTOBER") { month = 10; }
	if (s == "NOVEMBER") { month = 11; }
	if (s == "DECEMBER") { month = 12; }

}
void Date::print() const {
	cout << month << "/" << day << "/" << year << endl;
}
void Date::printDDDYYYY() const {
	int yyyy = 0;
	int ddd = 0;
	int count[13] = { 0,0,31,59,90,120,151,181,212,243,273,304,334 };
	ddd = count[month] + day;
	yyyy = year;
	cout << ddd << "/" << yyyy << endl;
}
void Date::printMMDDYY() const {
	int yy = 0;
	yy = year % 100;
	if (month < 10) {
		cout << "0" << month << "/";
	}
	else {
		cout << month << "/";
	}
	if (day < 10) {
		cout << "0" << day << "/";
	}
	else {
		cout << day << "/";
	}
	cout << yy << endl;
}
void Date::printMonthDDYYYY() const {
	string change[13] = { "","JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST",
		"SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER" };
	string Month = change[month];
	cout << Month << "," << day << "," << year << endl;

}
Date::~Date() {
	cout << "Date object destructorn for Date" << month << "/" << day << "/" << year << endl;
}
int main() {
	int d = 0, m = 0, y = 0;
	cout << "请按照日月年输入日期" << endl;
	cin >> d >> m >> y;
	Date a(d, m, y);
	cin >> d >> m >> y;
	Date b(d, m, y);
	cin >> d >> m >> y;
	Date c(d, m, y);
	cin >> d >> m >> y;
	Date n(d, m, y);
	a.print();
	b.print();
	c.print();
	n.print();
	a.printDDDYYYY();
	b.printDDDYYYY();
	c.printDDDYYYY();
	n.printDDDYYYY();
	a.printMMDDYY();
	b.printMMDDYY();
	c.printMMDDYY();
	n.printMMDDYY();
	a.printMonthDDYYYY();
	b.printMonthDDYYYY();
	c.printMonthDDYYYY();
	n.printMonthDDYYYY();
	system("pause");
	return 0;
}