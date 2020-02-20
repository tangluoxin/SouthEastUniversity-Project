#include<iostream>
#include<vector>
#include"account.h"
#include"savingsaccount.h"
#include"CheckingAccount.h"
using namespace std;
int main()
{
	SavingsAccount account1(25.0, 0.03); // create SavingsAccount object
	CheckingAccount account2(80.0, 1.0); // create CheckingAccount object
	SavingsAccount account3(200.0, 0.03); // create SavingsAccount object
	CheckingAccount account4(400.0, 1.0); // create CheckingAccount object

	vector<Account *>account(4);
	account[0] =  &SavingsAccount (25.0, 0.03);
	account[1] =  &CheckingAccount (80.0, 1.0);
	account[2] =  &SavingsAccount(200.0, 0.015);
	account[3] =  &CheckingAccount(400.0, 1.0);
	
	cout << "account1 balance: $" << account[0]->getBalance() << endl;
	cout << "\nAttempting to debit $25.00 from account1:";
	account[0]->debit(10.0);
	cout << "\nCrediting $40.00 to account1:";
	account[0]->credit(30.0);
	SavingsAccount*ptr1 = dynamic_cast<SavingsAccount*>(account[0]);
	if (ptr1 != 0) {
		double interestEarned = account[0]->calculateInterest();
		cout << "\nAdding $"; account[0]->credit(interestEarned); cout<< " interest to account1." << endl;
	}
	cout << "account1 balance: $" << account[0]->getBalance() << endl;
	cout << endl;

	cout << "account2 balance: $" << account[1]->getBalance();
	cout << "\nAttempting to debit $0.00 from account2:";
	account[1]->debit(0.0);
	cout << "\nCrediting $10.00 to account2:";
	account[1]->credit(10.0);
	SavingsAccount*ptr2 = dynamic_cast<SavingsAccount*>(account[1]);
	if (ptr2 != 0) {
		double interestEarned = account[1]->calculateInterest();
		cout << "\nAdding $" << interestEarned << " interest to account2."
			<< endl;
	}
	cout << "account1 balance: $" << account[1]->getBalance() << endl;
	cout << endl;


	cout << "account3 balance: $" << account[2]->getBalance();
	cout << "\nAttempting to debit $10.00 from account3:";
	account[2]->debit(10.0);
	cout << "\nCrediting $0.00 to account3:";
	account[2]->credit(0.0);
	SavingsAccount*ptr3 = dynamic_cast<SavingsAccount*>(account[2]);
	if (ptr3 != 0) {
		double interestEarned = account[2]->calculateInterest();
		cout << "\nAdding $"; account[2]->credit(interestEarned); cout << " interest to account3." << endl;
	}
	cout << "account3 balance: $" << account[2]->getBalance() << endl;
	cout << endl;

	cout << "account4 balance: $" << account[3]->getBalance();
	cout << "\nAttempting to debit $0.00 from account4:";
	account[3]->debit(0.0);
	cout << "\nCrediting $0.00 to account4:";
	account[3]->credit(0.0);
	SavingsAccount*ptr4 = dynamic_cast<SavingsAccount*>(account[3]);
	if (ptr4 != 0) {
		double interestEarned = account[3]->calculateInterest();
		cout << "\nAdding $" << interestEarned << " interest to account4."
			<< endl;
	}
	cout << "account4 balance: $" << account[3]->getBalance() << endl;
	cout << endl;


	system("pause");
	return 0;
} // end main
