#ifndef HIGHCREDITACCOUNT_H
#define HIGHCREDITACCOUNT_H

#include "Account.h"

class HighCreditAccount : public Account
{
	private:
		double interestRatio;
		int CreditRate;

	public:
		HighCreditAccount(int accountNumber, int money, char *name, double interestRatio, int CreditRate)
			: Account(accountNumber, money, name)
		{
			this->interestRatio = interestRatio;
			this->CreditRate = CreditRate;
		}
        void Deposit(int money)
        {
			int	temp = 0;
            temp += (int) (money * interestRatio / 100);
			temp += (int) (money * CreditRate / 100);
			Account::Deposit(money + temp);
        }
};

#endif