#include <iostream>
using namespace std;

typedef struct 
{
	int accID;
	char name[100];
	int money;
} Account;

Account account[100];
int accIdx = 0;

namespace banksystem
{
	int FindAccount(int id)
	{
		for (int i = 0; i < accIdx; i++)
		{
			if (account[i].accID == id)
				return (1);
		}
		cout << "존재하지 않는 계좌 입니다." << endl;
		return (0);
	}
	void ShowMenu(void)
	{
		cout << "------Menu------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
	}

	void MakeAccount()
	{
		cout << "[계좌개설]" << endl;
		cout << "계좌ID: ";
		cin >> account[accIdx].accID;
		cout << "이 름: ";
		cin >> account[accIdx].name;
		cout << "입금액: ";
		cin >> account[accIdx].money;
		accIdx++;
	}
	void Deposit()
	{
		int id;
		int deposit;

		cout << "[입	금]" << endl;
		cout << "계좌ID: ";
		cin >> id;
		if (!FindAccount(id))
			return ;
		cout << "입금액: ";
		cin >> deposit;
		account[id].money += deposit;
		cout << "입금완료" << endl << endl;

	}
	void Withdraw()
	{
		int id;
		int withdraw;

		cout << "[출	금]" << endl;
		cout << "계좌ID: ";
		cin >> id;
		if (!FindAccount(id))
			return ;
		cout << "입금액: ";
		cin >> withdraw;
		if (account[id].money < withdraw)
		{
			cout << "잔액부족" << endl << endl;
			return ;
		}
		account[id].money -= withdraw;
		cout << "출금완료" << endl << endl;
	}
	void ShowAccountInfo()
	{
		for (int i = 0; i < accIdx; i++)
		{
			cout << "계좌ID: " << account[i].accID << endl;
			cout << "이 름: " << account[i].name << endl;
			cout << "잔 액: " << account[i].money << endl << endl;
		}
	}
	void ProgramExit()
	{
		cout << "프로그램을 종료합니다." << endl;
	}
}
int main(void)
{
	int choice;

	while (true)
	{
		banksystem::ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;
	
		switch (choice)
		{
		case 1:
			banksystem::MakeAccount();
			break;
		case 2:
			banksystem::Deposit();
			break;
		case 3:
			banksystem::Withdraw();
			break;
		case 4:
			banksystem::ShowAccountInfo();
			break;
		case 5:
			banksystem::ProgramExit();
			return 0;
		default:
			cout << "잘못된 접근입니다." << endl;
		}
	}
    return 0;
}