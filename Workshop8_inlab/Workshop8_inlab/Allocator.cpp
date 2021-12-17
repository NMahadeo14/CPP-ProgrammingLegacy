/*
NAME: Devin Mahadeo
STUDENT #: 160611174
EMAIL: Dmahadeo2@myseneca.ca
*/
#include <iostream>
#include "iAccount.h"
#include "SavingsAccount.h"

namespace sict
{
	const double interest = 0.05;
	iAccount * CreateAccount(const char* type, double balence)
	{
		iAccount * NewAccount = nullptr;

		if (type[0] == 'S')
		{
			NewAccount = new SavingsAccount(balence, interest);
			return NewAccount;
		}
		else
		{
			return nullptr;
		}
	}
};
