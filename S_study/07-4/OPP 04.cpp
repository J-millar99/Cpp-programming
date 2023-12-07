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
    EXIT = 5,
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
        void Deposit(int money)
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

            void SysCreateAccount(void)
            {
                int accountNumber;
                char name[100];
                int money;

                cout << "[계좌개설]" << endl;
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
                accountData[accountCnt++] = new Account(accountNumber, money, name);
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
            BankSystem.SysCreateAccount();
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