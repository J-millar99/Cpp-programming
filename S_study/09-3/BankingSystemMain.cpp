#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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