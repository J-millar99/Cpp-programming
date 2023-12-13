#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

AcconuntHandler::AcconuntHandler() : accountCnt(0) {}

AcconuntHandler::~AcconuntHandler()
{
	for (int i = 0; i < accountCnt; i++)
	{
		delete accountData[i];
	}
}

void AcconuntHandler::SysShowMenu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AcconuntHandler::SysSelectAccount(void)
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
		cout << "올바르지 않은 선택입니다." << endl;
}

void AcconuntHandler::SysCreateNormalAccount()
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

void AcconuntHandler::SysCreateHighCreditAccount()
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
		cout << "올바르지 않은 선택입니다." << endl;
		return;
	}
	accountData[accountCnt++] = new HighCreditAccount(accountNumber, money, name, interestRatio, CreditRate);
}

void AcconuntHandler::SysDeposit(void)
{
	int accountNumber;
	int money;
	int idx;

	cout << "[입  금]" << endl;
	cout << "계좌ID: ";
	cin >> accountNumber;
	cout << "입금액: ";
	cin >> money;
	idx = FindAccount(accountNumber);
	if (idx == -1)
		cout << "존재하지 않는 계좌입니다." << endl;
	else
		accountData[idx]->Deposit(money);
}

void AcconuntHandler::SysWithdraw(void)
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

void AcconuntHandler::SysPrintAccountInfo(void)
{
	int idx = 0;

	while (idx < accountCnt)
	{
		accountData[idx]->PrintAccountInfo();
		idx++;
	}
}

int AcconuntHandler::SysExitProgram(void)
{
	cout << "프로그램을 종료합니다." << endl;
	return 0;
}

int AcconuntHandler::FindAccount(int findNumber)
{
	for (int i = 0; i < accountCnt; i++)
	{
		if (accountData[i]->AccountID() == findNumber)
			return i;
	}
	return -1;
}