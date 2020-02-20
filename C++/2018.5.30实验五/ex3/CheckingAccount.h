#pragma once
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include"account.h"
using namespace std;

class CheckingAccount:public Account {
public:
	CheckingAccount(double initialBalance = 0.0, double fee = 0.0);
	virtual void credit(double);
	virtual bool debit(double);
private:
	double transactionFee;
};
#endif // !CHECKINGACCOUNT
