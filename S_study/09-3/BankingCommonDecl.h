#ifndef BANKINGCOMMONDECL_H
#define BANKINGCOMMONDECL_H

#include <iostream>
#include <cstring>
#include <cstdlib>
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

#endif