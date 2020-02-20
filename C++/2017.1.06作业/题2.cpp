#include<iostream>
using namespace std;
class Date {
	int year=0, mounth=0, day=0;
public:
	bool displaydate(int year, int mounth, int day) {
		if (mounth != 2 && mounth != 4 && mounth != 6 && mounth != 9 && mounth != 11 && day <= 31) 
		{ return true; }
		else if (mounth == 4 || mounth == 6 || mounth == 9 || mounth == 11) {
			if (day <= 30) { return true; }
			else { return false; }
		}
		else if (mounth == 2) {
			if (day <= 28) { return true; }
			else if (year % 100 == 0 && year % 400 == 0 && day <= 29) 
			{ return true; }
			else if (year % 100 != 0 && year % 4 == 0 && day <= 29) 
			{ return true; }
			else { return false; }
		}
		else { return false; }
	}
};
int main() {
	cout << "Please enter Year Mounth Day" << endl;
	int i = 0, year = 0, mounth = 0, day = 0;
	cin >> year >> mounth >> day;
	Date M;
	i = M.displaydate(year, mounth, day);
	if (i == 1) { cout << "Date is: " << mounth << "/" << day << "/" << year; }
	else { cout << "worse date"; }
	system("pause");
	return 0;
}
