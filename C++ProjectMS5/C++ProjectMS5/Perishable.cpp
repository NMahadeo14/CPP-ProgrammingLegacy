#include <iostream>
#include <iomanip>
#include "Perishable.h"

using namespace std;

namespace ama
{
	Perishable::Perishable() : Product('P')
	{
		m_expirydate = Date();
	}

	std::ostream& Perishable::write(std::ostream& out, int writeMode) const 
	{
		if (isEmpty() == true)
		{
			return out;
		}
		else
		{
			Product::write(out, writeMode);
			if (writeMode == write_human)
			{
				out << setw(max_length_label) << right << "Expiry Date: "; 
				m_expirydate.write(out);
				out << endl;
			}
			else if (writeMode == write_table)
			{
				out << " ";
				m_expirydate.write(out);
				out << " |";
			}
			else if (writeMode == write_condensed)
			{
				out << ',';
				m_expirydate.write(out);
			}
		}

		return out;	
	}

	std::istream& Perishable::read(std::istream& in, bool interacctive)
	{
		if (interacctive == true)
		{
			Product::read(in, true);
			
			cout.width(max_length_label);
			cout.setf(ios::right);
			cout << "Expiry date (YYYY/MM/DD): ";
			m_expirydate.read(in);

			if (in.fail())
			{
				if (m_expirydate.status() == error_year)
				{
					Product::message("Invalid Year in Date Entry");
				}
				else if (m_expirydate.status() == error_mon)
				{
					Product::message("Invalid Month in Date Entry");
				}
				else if (m_expirydate.status() == error_day)
				{
					Product::message("Invalid Day in Date Entry");
				}
				else
				{
					Product::message("Invalid Date Entry");
				}
				m_expirydate = Date();

			}

		}
		else
		{
			Product::read(in, interacctive);
			m_expirydate.read(in);
			if (in.fail())
			{
				m_expirydate = Date();
			}
		}

		return in;
	}


}

