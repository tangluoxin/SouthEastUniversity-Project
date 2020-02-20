#include<iostream>
#include<string>
using namespace std;
class Employee {
	string fname, lname;
	int ysalary = 0;
public:
	void setEmployee(string firstname, string lastname, int mouthsalary) {
		fname = firstname; lname = lastname; ysalary = mouthsalary * 12;
	}
	string getfname() { return fname; }
	string getlname() { return lname; }
	int getysalary() { return ysalary; }
};
int main() {
	Employee a, b;
	a.setEmployee("Bob", "Jones", 3000);
	b.setEmployee("Susan", "Baker", 4000);
	cout << "Employee one:" << a.getfname() << ";" << a.getlname() << ";" << a.getysalary() << endl;
	cout << "Employee two:" << b.getfname() << ";" << b.getlname() << ";" << b.getysalary() << endl;
	cout << "Increasing emlpoyee salaries by 10%:" << endl;
	cout << "Employee one:" << a.getfname() << ";" << a.getlname() << ";" << 1.1* a.getysalary() << endl;
	cout << "Employee two:" << b.getfname() << ";" << b.getlname() << ";" << 1.1*b.getysalary() << endl;
	system("pause");
	return 0;
}
