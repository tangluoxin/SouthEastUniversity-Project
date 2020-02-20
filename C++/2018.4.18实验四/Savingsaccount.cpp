#include<iostream>
#include"savingsaccount.h"
using namespace std;
SavingsAccount::SavingsAccount(double initialBalance , double rate ):Account(initialBalance) {
	interestRate = rate;
}
double SavingsAccount::calculateInterest() {
	return getBalance()*interestRate;
}