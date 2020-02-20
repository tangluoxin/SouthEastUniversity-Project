#pragma once
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include"account.h"
using namespace std;

class SavingsAccount :public Account {
public:
	SavingsAccount(double initialBalance = 0.0, double rate = 0.0);//存款初始值和利率
	virtual double calculateInterest();
private:
	double interestRate;//利率
};
#endif // !SAVINGACCOUNT_H
