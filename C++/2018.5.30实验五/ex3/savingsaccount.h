#pragma once
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include"account.h"
using namespace std;

class SavingsAccount :public Account {
public:
	SavingsAccount(double initialBalance = 0.0, double rate = 0.0);//����ʼֵ������
	virtual double calculateInterest();
private:
	double interestRate;//����
};
#endif // !SAVINGACCOUNT_H
