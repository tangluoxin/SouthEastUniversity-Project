#include<iostream>
#include<iomanip>
using namespace std;
class SavingsAccount
{
public:
	// constructor sets balance to value greater than or equal to zero
	SavingsAccount(double b)
	{
		savingsBalance = (b >= 0.0 ? b : 0.0);
	} // end SavingsAccount constructor
	void calculateMonthlyInterest(); // calculate interest; add to balance计算月利息
	void modifyInterestRate(double);//设置新的年利率
	void printBalance() const;
private:
	double savingsBalance; // the account balance当前存款额
	static double annualInterestRate; // the interest rate of all accounts年利率
}; // end class SavingsAccount
void  SavingsAccount::calculateMonthlyInterest() {
	savingsBalance += savingsBalance*annualInterestRate / 12;
}
void SavingsAccount::modifyInterestRate(double a) {
	annualInterestRate = a;
}
void SavingsAccount::printBalance() const {
	cout << savingsBalance;
}
double SavingsAccount::annualInterestRate=0;
int main() {
	SavingsAccount saver1(2000);
	SavingsAccount saver2(3000);
	cout << "Initial balances:" << endl << "saver 1:";
	saver1.printBalance(); cout << endl;
	cout << "saver 2:";
	saver2.printBalance(); cout << endl;
	saver1.modifyInterestRate(0.03);
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();
	cout << "Balances after 1 month's interests applied at 0.03:" << endl;
	cout << "saver 1:"; 
	saver1.printBalance(); cout << endl;
	cout << "saver 2:"; 
	saver2.printBalance(); cout << endl;
	saver1.modifyInterestRate(0.04);
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();
	cout << "Balances after 1 month's interests applied at 0.04:" << endl;
	cout << "saver 1:"; 
	saver1.printBalance(); cout << endl;
	cout << "saver 2:"; 
	saver2.printBalance(); cout << endl;
	system("pause");
	return 0;
}