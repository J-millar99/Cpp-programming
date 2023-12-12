#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int accountNumber, int money, char *name)
{
	this->accountNumber = accountNumber;
	this->money = money;
	this->name = new char(strlen(name) + 1);
	strcpy(this->name, name);
}

Account::Account(const Account &copy) : accountNumber(copy.accountNumber), money(copy.money)
{
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

Account::~Account()
{
	delete[] name;
}

int Account::AccountID() const
{
	return this->accountNumber;
}
void Account::Deposit(int money)
{
	cout << "입금완료" << endl;
	this->money += money;
}
void Account:: Withdraw(int money)
{
	if (this->money < money)
		cout << "잔액이 부족합니다." << endl;
	else
	{
		cout << "출금완료" << endl;
		this->money -= money;
	}
}
void Account::PrintAccountInfo() const
{
	cout << "계좌ID: " << this->accountNumber << endl;
	cout << "이 름: " << this->name << endl;
	cout << "잔 액: " << this->money << endl;
}