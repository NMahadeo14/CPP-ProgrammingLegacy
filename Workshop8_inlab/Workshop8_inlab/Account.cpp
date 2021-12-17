/*
NAME: Devin Mahadeo
STUDENT #: 160611174
EMAIL: Dmahadeo2@myseneca.ca
*/
#include <iostream>
#include "Account.h"

namespace sict
{
	Account::Account(double balence)
	{
		if (balence < 0 || balence == '\0')
		{
			this->m_balence = 0.00;
		}
		else
		{
			this->m_balence = balence;
		}
	}

	bool Account::credit(double amount)
	{
		if (amount > 0)
		{
			this->m_balence += amount;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Account::debit(double amount)
	{
		if (amount > this->m_balence || amount < 0)
		{
			return false;
		}
		else
		{
			this->m_balence -= amount;
			return true;
		}
	}

	double Account::balence() const
	{
		return this->m_balence;
	}

};