#include <iostream>
#include "Account.h"
#include "ChequingAccount.h"

using namespace std;

namespace sict
{
	ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) :Account(balance)
	{
		if ((balance < 0 || balance == '\0') && (transFee < 0 || transFee == '\0') && (monthlyFee < 0 || monthlyFee == '\0'))
		{
			this->m_transactionFee = 0.0;
			this->m_monthlyFee = 0.0;
		}
		else
		{
			this->m_transactionFee = transFee;
			this->m_monthlyFee = monthlyFee;
		}
	}

	bool ChequingAccount::credit(double amount)
	{
		if (Account::credit(amount) == true)
		{
			Account::debit(m_transactionFee);

			return true;
		}
		else
		{
			return false;
		}
	}

	bool ChequingAccount::debit(double amount)
	{
		if (Account::debit(amount) == true)
		{
			Account::debit(m_transactionFee);

			return true;
		}
		else
		{
			return false;
		}
	}

	void ChequingAccount::monthEnd()
	{
		Account::debit(m_monthlyFee);
	}

	void ChequingAccount::display(std::ostream& out) const
	{
		out << "Account type: Chequing" << endl;
		out.precision(2);
		out.setf(ios::fixed);
		out << "Balance: $" << Account::balance() << endl;
		out.precision(2);
		out.setf(ios::fixed);
		out << "Per Transaction Fee: " << (m_transactionFee) << endl;
		out.precision(2);
		out.setf(ios::fixed);
		out << "Monthly Fee: " << (m_monthlyFee) << endl;

	}
			
};