#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

enum
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT = 5
};

enum
{
	CreditRate_A = 7,
	CreditRate_B = 4,
	CreditRate_C = 2
};

class Account
{
    private:
        int accountNumber;
        int money;
        char *name;
    
    public:
        Account(int accountNumber, int money, char *name)
        {
            this->accountNumber = accountNumber;
            this->money = money;
            this->name = new char(strlen(name) + 1);
            strcpy(this->name, name);
        }
        Account(const Account &copy) : accountNumber(copy.accountNumber), money(copy.money)
        {
            name = new char[strlen(copy.name) + 1];
            strcpy(name, copy.name);
        }
        ~Account()
        {
            delete []name;
        }
        int AccountID() const
        {
            return this->accountNumber;
        }
        virtual void Deposit(int money)
        {
            cout<<"입금완료"<<endl;
            this->money += money;
        }
        void Withdraw(int money)
        {
            if (this->money < money)
                cout<<"잔액이 부족합니다."<<endl;
            else
            {
                cout<<"출금완료"<<endl;
                this->money -= money;
            }
        }
        void PrintAccountInfo() const
        {
            cout<<"계좌ID: "<<this->accountNumber<<endl;
            cout<< "이 름: "<<this->name<<endl;
            cout<< "잔 액: "<<this->money<<endl;
        }
};

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

class AcconuntHandler
{
    private:
        int accountCnt;
        Account *accountData[100];
    
        public:
            AcconuntHandler() : accountCnt(0) {}
            ~AcconuntHandler()
            {
                for (int i = 0; i < accountCnt; i++)
                {
                    delete accountData[i];
                }
            }
            void SysShowMenu(void)
            {
                cout<<"-----Menu-----"<<endl;
                cout<<"1. 계좌개설"<<endl;
                cout<<"2. 입 금"<<endl;
                cout<<"3. 출 금"<<endl;
                cout<<"4. 계좌정보 전체 출력"<<endl;
                cout<<"5. 프로그램 종료"<<endl;
            }

            void SysSelectAccount(void)
            {
				int choice;

				cout << "[계좌종류선택]" << endl;
				cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
				cout << "선택: ";
				cin >> choice;
				if (choice == 1)
					SysCreateNormalAccount();
				else if (choice == 2)
					SysCreateHighCreditAccount();
				else
					cout << "올바르지 않은 선택입니다."<<endl;
			}

			void SysCreateNormalAccount()
			{
				int accountNumber;
                char name[100];
                int money;
				double interestRatio;

				cout << "[보통예금계좌 개설]" << endl;
				cout << "계좌ID: ";
                cin >> accountNumber;
                if (accountNumber <= 0)
                {
                    cout << "올바르지 않은 계좌 ID입니다." << endl;
                    return;
                }
                cout << "이 름: ";
                cin >> name;
                cout << "입금액: ";
                cin >> money;
				cout << "이자율: ";
				cin >> interestRatio;
                accountData[accountCnt++] = new NormalAccount(accountNumber, money, name, interestRatio);
			}

			void SysCreateHighCreditAccount()
			{
                int accountNumber;
                char name[100];
                int money;
				double interestRatio;
				int CreditRate;

				cout << "[신용신뢰계좌 개설]" << endl;
				cout << "계좌ID: ";
                cin >> accountNumber;
                if (accountNumber <= 0)
                {
                    cout << "올바르지 않은 계좌 ID입니다." << endl;
                    return;
                }
                cout << "이 름: ";
                cin >> name;
                cout << "입금액: ";
                cin >> money;
				cout << "이자율: ";
				cin >> interestRatio;
				cout << "신용둥급(1toA, 2toB, 3toC): ";
				cin >> CreditRate;
				if (CreditRate == 1)
					CreditRate = CreditRate_A;
				else if (CreditRate == 2)
					CreditRate = CreditRate_B;
				else if (CreditRate == 3)
					CreditRate = CreditRate_C;
				else
				{
					cout << "올바르지 않은 선택입니다."<<endl;
					return ;
				}
				accountData[accountCnt++] = new HighCreditAccount(accountNumber, money, name, interestRatio, CreditRate);
			}

            void SysDeposit(void)
            {
                int accountNumber;
                int money;
                int idx;

                cout<<"[입  금]"<<endl;
                cout<<"계좌ID: ";
                cin>>accountNumber;
                cout<<"입금액: ";
                cin>>money;
                idx = FindAccount(accountNumber);
                if (idx == -1)
                    cout<<"존재하지 않는 계좌입니다."<<endl;
                else
                    accountData[idx]->Deposit(money);
            }

            void SysWithdraw(void)
            {
                int accountNumber;
                int money;
                int idx;

                cout << "[출  금]" << endl;
                cout << "계좌ID: ";
                cin >> accountNumber;
                cout << "출금액: ";
                cin >> money;
                idx = FindAccount(accountNumber);
                if (idx == -1)
                    cout << "존재하지 않는 계좌입니다." << endl;
                else
                    accountData[idx]->Withdraw(money);
            }

            void SysPrintAccountInfo(void)
            {
                int idx = 0;

                while (idx < accountCnt)
                {
                    accountData[idx]->PrintAccountInfo();
                    idx++;
                }
            }

            int SysExitProgram(void)
            {
                cout << "프로그램을 종료합니다." << endl;
                return 0;
            }

            int FindAccount(int findNumber)
            {
                for (int i = 0; i < accountCnt; i++)
                {
                    if (accountData[i]->AccountID() == findNumber)
                        return i;
                }
                return -1;
            }
};

int main(void)
{
    AcconuntHandler BankSystem;
    int code;

    while (1)
    {
        BankSystem.SysShowMenu();
        cout<<"선택: ";
        cin>>code;
        cout<<endl;
        switch (code)
        {
        case MAKE:
            BankSystem.SysSelectAccount();
            break ;
        case DEPOSIT:
            BankSystem.SysDeposit();
            break ;
        case WITHDRAW:
            BankSystem.SysWithdraw();
            break ;
        case INQUIRE:
            BankSystem.SysPrintAccountInfo();
            break ;
        case EXIT:
            return (BankSystem.SysExitProgram());
        default:
            cout<<"잘못된 선택번호입니다."<<endl;
        }
    }
    return 0;
}