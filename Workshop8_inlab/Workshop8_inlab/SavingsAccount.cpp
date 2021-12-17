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
	SavingsAccount::SavingsAccount(double balence, double interestRate):Account(balence)
	{
		if ((balence < 0 || balence == '\0') && (interestRate < 0 || interestRate == '\0'))
		{
			this->m_balence = 0.00;
			this->m_Irate = 0.0;
		}
		else
		{
			this->m_balence = balence;
			this->m_Irate = interestRate;
		}
	}

	void SavingsAccount::monthEnd()
	{
		credit(m_Irate * Account::balence());
	}

	void SavingsAccount::display(std::ostream& out) const
	{
		out << "Account type: Savings" << endl;
		out.precision(2);
		out.setf(ios::fixed);
		out << "Balance: $" << Account::balence() << endl;
		out.precision(2);
		out.setf(ios::fixed);
		out << "Interest Rate (%): " << (m_Irate * 100) << endl;
		
	
	}


};