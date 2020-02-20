#include<iostream>
#include"account.h"
using namespace std;


Account::Account(double initialBalance)
{
	// if initialBalance is greater than or equal to 0.0, set this value 
	// as the balance of the Account
	if(initialBalance>=0)
		balance = initialBalance;
   else // otherwise, output message and set balance to 0.0
   {
	   cout << "Error: Initial balance cannot be negative." << endl;
	   balance = 0.0;
   } // end if...else
} // end Account constructor

  // credit (add) an amount to the account balance
void Account::credit(double amount)
{
	cout << amount;
	balance = balance + amount; // add amount to balance
} // end function credit

  // debit (subtract) an amount from the account balance
  // return bool indicating whether money was debited
bool Account::debit(double amount)
{
	if (amount > balance) // debit amount exceeds balance
	{
		cout << "Debit amount exceeded account balance." << endl;
		return false;
	} // end if
	else // debit amount does not exceed balance
	{
		balance = balance - amount;
		cout << amount;
		return true;
	} // end else
} // end function debit
  // set the account balance
void Account::setBalance(double newBalance)
{
	balance = newBalance;
} // end function setBalance
  // return the account balance
double Account::getBalance()
{
	return balance;
} // end function getBalance
double Account::calculateInterest() {
	return 0;
}