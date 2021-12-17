#include <iostream>
#include "CellPhone.h"

using namespace std;
namespace sict
{
	void display(const CellPhone& phone)
	{
		cout << "Phone " << phone.m_model << " costs $" << phone.m_price <<
			"!" << endl;
	};

	void display(const CellPhone* Phone, int amount)
	{
		int i = 0; 
		double m_smallestprice = Phone[i].m_price;
		cout << "------------------------------" << endl;
		cout << "Phones available at the mall:" << endl;
		cout << "------------------------------" << endl;
		for (i = 0; i < amount; i++)
		{
			cout << i + 1 << ". Phone " << Phone[i].m_model << " costs $" << Phone[i].m_price << "!" << endl;
			if (Phone[i].m_price < m_smallestprice)
			{
				m_smallestprice = Phone[i].m_price;
			}
		}
		cout << "------------------------------" << endl;
		cout << "The cheapest phone costs $" << m_smallestprice << "." << endl;
		cout << "------------------------------" << endl;

	}

}




