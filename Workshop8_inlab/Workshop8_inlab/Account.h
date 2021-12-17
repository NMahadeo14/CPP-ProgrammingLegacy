/*
NAME: Devin Mahadeo
STUDENT #: 160611174
EMAIL: Dmahadeo2@myseneca.ca
*/
#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H
#include <iostream>
#include "iAccount.h"

namespace sict
{
	class Account : public iAccount
	{
		double m_credit;
		double m_debit;
		double m_balence;

	public:

		Account(double balence);
		bool credit(double amount);
		bool debit(double amount);
	protected:
		double balence() const;
	};
}
#endif // !SICT_ACCOUNT_H

