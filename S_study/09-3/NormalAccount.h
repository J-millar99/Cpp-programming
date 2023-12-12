#ifndef NORMALACCOUNT_H
#define NORMALACCOUNT_H

#include "Account.h"

class NormalAccount : public Account
{
	private:
		double interestRatio;

	public:
		NormalAccount(int accountNumber, int money, char *name, double interestRatio)
			: Account(accountNumber, money, name)
		{
			this->interestRatio = interestRatio;
		}
        void Deposit(int money)
        {
            money = (int) (money + (money * interestRatio / 100));
			Account::Deposit(money);
        }
};

#endif