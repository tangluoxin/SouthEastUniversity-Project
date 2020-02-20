#include<iostream>
#include"CheckingAccount.h"
using namespace std;
CheckingAccount::CheckingAccount(double initialBalance , double fee ) :Account(initialBalance) {
	transactionFee = fee;
}
void CheckingAccount::credit(double amount){
	
		double a = 0.0;
		a = getBalance() + amount - transactionFee;
		setBalance(a);
	
}
bool CheckingAccount::debit(double amount) {
	if (amount > 0) {
		if (amount > getBalance()) // debit amount exceeds balance
		{
			cout << "Debit amount exceeded account balance." << endl;
			return false;
		} // end if
		else // debit amount does not exceed balance
		{
			double a = 0.0;
			a = getBalance() - amount - transactionFee;
			setBalance(a);
			return true;
		} // end else
	}
}