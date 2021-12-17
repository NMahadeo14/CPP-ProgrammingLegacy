/*
NAME: Devin Mahadeo
STUDENT #: 160611174
EMAIL: Dmahadeo2@myseneca.ca
*/
#include <iostream>
#include "iAccount.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict
{
	const double interest = 0.05;
	const double transaction = 0.50;
	const double monthly = 2.00;

	iAccount * CreateAccount(const char* type, double balance)
	{
		iAccount * NewAccount = nullptr;

		if (type[0] == 'S')
		{
			NewAccount = new SavingsAccount(balance, interest);
			return NewAccount;
		}
		else if (type[0] == 'C')
		{
			NewAccount = new ChequingAccount(balance, transaction, monthly);
			return NewAccount;
		}
		else
		{
			return nullptr;
		}
	}
};
