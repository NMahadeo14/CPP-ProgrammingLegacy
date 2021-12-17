/*
NAME: Devin Mahadeo
STUDENT #: 160611174
EMAIL: Dmahadeo2@myseneca.ca
*/
#include <iostream>
#include "Account.h"

namespace sict
{
	Account::Account(double balance)
	{
		if (balance < 0 || balance == '\0')
		{
			this->m_balance = 0.00;
		}
		else
		{
			this->m_balance = balance;
		}
	}

	bool Account::credit(double amount)
	{
		if (amount > 0)
		{
			this->m_balance += amount;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Account::debit(double amount)
	{
		if (amount > this->m_balance || amount < 0)
		{
			return false;
		}
		else
		{
			this->m_balance -= amount;
			return true;
		}
	}

	double Account::balance() const
	{
		return this->m_balance;
	}

};