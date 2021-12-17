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

}


