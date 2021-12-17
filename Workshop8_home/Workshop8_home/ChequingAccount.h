#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H
#include <iostream>
#include "Account.h"

namespace sict
{
	class ChequingAccount : public Account
	{
		double m_balance;
		double m_transactionFee;
		double m_monthlyFee;

	public:

		ChequingAccount(double balance, double transFee, double monthlyFee);
		bool credit(double amount);
		bool debit(double amount);
		void monthEnd();
		void display(std::ostream& out) const;

	
	};
};

#endif
