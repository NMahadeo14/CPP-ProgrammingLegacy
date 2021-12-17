#ifndef SICT_CELLPHONE_H
#define SICT_CELLPHONE_H

namespace sict
{
	struct CellPhone
	{
		char m_model[33];
		double m_price;
	};


	void display(const CellPhone&);
}

#endif
