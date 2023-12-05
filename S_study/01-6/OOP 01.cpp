#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct
{
    int accountNumber;
    int money;
    char name[100];
}   account;

void ShowMenu(void);
void CreateAccount(account *data);
void Deposit(account *data);
void Withdraw(account *data);
void PrintAccountInfo(account *data);
int exitProgram(account *data);
void initAccount(account *data);
int findAccount(account *data, int accountNumber);

int main(void)
{
    account data[100];
    int code;

    initAccount(data);
    while (1)
    {
        ShowMenu();
        cout<<"선택: ";
        cin>>code;
        cout<<endl;
        if (code == 1)
            CreateAccount(data);
        else if (code == 2)
            Deposit(data);
        else if(code == 3)
            Withdraw(data);
        else if (code == 4)
            PrintAccountInfo(data);
        else if (code == 5)
            return (exitProgram(data));
        else
            cout<<"잘못된 선택번호입니다."<<endl;
    }
    return 0;
}

void ShowMenu(void)
{
    cout<<"-----Menu-----"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}

void CreateAccount(account *data)
{
    int idx = 0;

    while (idx < 100)
    {
        if (data[idx].accountNumber == -1)
        {
            cout << "[계좌개설]" << endl;
            cout << "계좌ID: ";
            cin >> data[idx].accountNumber;
            if (data[idx].accountNumber <= 0)
            {
                cout << "올바르지 않은 계좌 ID입니다." << endl;
                data[idx].accountNumber = -1;
                return ;
            }
            cout << "이 름: ";
            cin >> data[idx].name;
            cout << "입금액: ";
            cin >> data[idx].money;
            return ;
        }
        idx++;
    }
}

void Deposit(account *data)
{
    int accountNumber;
    int money;
    int idx;

    cout<<"[입  금]"<<endl;
    cout<<"계좌ID: ";
    cin>>accountNumber;
    cout<<"입금액: ";
    cin>>money;
    idx = findAccount(data, accountNumber);
    if (idx == -1)
        cout<<"존재하지 않는 계좌입니다."<<endl;
    else
        data[idx].money += money;
}

void Withdraw(account *data)
{
    int accountNumber;
    int money;
    int idx;

    cout<<"[출  금]"<<endl;
    cout<<"계좌ID: ";
    cin>>accountNumber;
    cout<<"출금액: ";
    cin>>money;
    idx = findAccount(data, accountNumber);
    if (idx == -1)
        cout<<"존재하지 않는 계좌입니다."<<endl;
    else
    {
        if (money > data[idx].money)
            cout<<"잔액이 부족합니다."<<endl;
        else
            data[idx].money -= money;
    }
}

void PrintAccountInfo(account *data)
{
    int idx = 0;

    while (idx < 100)
    {
        if (data[idx].accountNumber != -1)
        {
            cout<<"계좌ID: "<<data[idx].accountNumber<<endl;
            cout<< "이 름: "<<data[idx].name<<endl;
            cout<< "잔 액: "<<data[idx].money<<endl;
        }
        idx++;
    }
}

int exitProgram(account *data)
{
    cout<<"프로그램을 종료합니다."<<endl;
    return 0;
}

int findAccount(account *data, int accountNumber)
{
    int idx = 0;

    while (idx < 100)
    {
        if (data[idx].accountNumber == accountNumber)
            return idx;
        idx++;
    }
    return -1;
}

void initAccount(account *data)
{
    int idx = 0;

    while (idx < 100)
    {
        data[idx].accountNumber = -1;
        idx++;
    }
}