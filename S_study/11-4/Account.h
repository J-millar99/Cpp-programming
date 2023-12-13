#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
    private:
        int accountNumber;
        int money;
        char *name;
    
    public:
        Account(int accountNumber, int money, char *name);
        Account(const Account &copy);
        ~Account();
        int AccountID() const;
        virtual void Deposit(int money);
        void Withdraw(int money);
        void PrintAccountInfo() const;
		Account &operator=(const Account &ref);
};

#endif