#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H

#include "Account.h"

class AcconuntHandler
{
    private:
        int accountCnt;
        Account *accountData[100];
    
        public:
            AcconuntHandler();
            ~AcconuntHandler();

            void SysShowMenu(void);
            void SysSelectAccount(void);
			void SysCreateNormalAccount();
			void SysCreateHighCreditAccount();
            void SysDeposit(void);
            void SysWithdraw(void);
            void SysPrintAccountInfo(void);
            int SysExitProgram(void);
            int FindAccount(int findNumber);
};

#endif