/*
NAME: Devin Mahadeo
STUDENT #: 160611174
EMAIL: Dmahadeo2@myseneca.ca
*/
#ifndef SICT_SAVINGACCOUNT_H
#define SICT_SAVINGACCOUNT_H
#include <iostream>
#include "Account.h"

namespace sict
{
	class SavingsAccount : public Account
	{
		double m_balence;
		double m_Irate;
	public:

		SavingsAccount(double balence, double interestRate);
		void monthEnd();
		void display(std::ostream& out) const;
	};
}
#endif // !SICT_SAVINGACCOUNT_H
