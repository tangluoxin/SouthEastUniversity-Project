#include<iostream>
#include<iomanip>
#include<vector>
#include"Employee.h"
#include"CommissionEmployee.h"
#include"BasePlusCommissionEmployee.h"
#include"SalariedEmployee.h"
#include"HourlyEmployee.h"
#include"Date.h"
using namespace std;
int main() {
	cout << fixed << setprecision(2);
	Date a(8, 15, 1944);
	SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", a, 800);
	Date b(4, 29, 1960);
	HourlyEmployee hourlyEmployee("Karen", "Price", "222-22-2222", b, 16.75, 40);
	Date c(9, 8, 1954);
	CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", c, 10000, 0.06);
	Date d(3, 2, 1965);
	BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", d, 5000, 0.04, 300);
	cout << "Employees processed individually using static binding:" << endl;
	salariedEmployee.print(); cout << endl;
	cout << "earned $" << salariedEmployee.earnings(); cout << endl;
	hourlyEmployee.print(); cout << endl;
	cout << "earned $" << hourlyEmployee.earnings(); cout << endl;
	commissionEmployee.print(); cout << endl;
	cout << "earned $" << commissionEmployee.earnings(); cout << endl;
	basePlusCommissionEmployee.print(); cout << endl;
	cout << "earned $" << basePlusCommissionEmployee.earnings(); cout << endl;
	system("pause");
	return 0;
}