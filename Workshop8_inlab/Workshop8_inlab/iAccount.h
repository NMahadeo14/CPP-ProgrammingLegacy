/*
NAME: Devin Mahadeo
STUDENT #: 160611174
EMAIL: Dmahadeo2@myseneca.ca
*/
#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H
#include <iostream>

namespace sict
{

	class iAccount
	{

	public:
		virtual ~iAccount() {};
		virtual bool credit(double amount) = 0;
		virtual	bool debit(double amount) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream& out) const = 0;
	};

	iAccount * CreateAccount(const char* type, double balence);

};


#endif // !IACCOUNT_H

