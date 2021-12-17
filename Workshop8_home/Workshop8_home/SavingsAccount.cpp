/*
NAME: Devin Mahadeo
STUDENT #: 160611174
EMAIL: Dmahadeo2@myseneca.ca
*/
#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"

using namespace std;

namespace sict
{
	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance)
	{
		if ((balance < 0 || balance == '\0') && (interestRate < 0 || interestRate == '\0'))
		{
			this->m_balance = 0.00;
			this->m_Irate = 0.0;
		}
		else
		{
			this->m_balance = balance;
			this->m_Irate = interestRate;
		}
	}

	void SavingsAccount::monthEnd()
	{
		credit(m_Irate * Account::balance());
	}

	void SavingsAccount::display(std::ostream& out) const
	{
		out << "Account type: Savings" << endl;
		out.precision(2);
		out.setf(ios::fixed);
		out << "Balance: $" << Account::balance() << endl;
		out.precision(2);
		out.setf(ios::fixed);
		out << "Interest Rate (%): " << (m_Irate * 100) << endl;


	}


};