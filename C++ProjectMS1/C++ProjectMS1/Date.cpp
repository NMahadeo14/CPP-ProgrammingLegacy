#include "Date.h"
#include <iostream>
#include <fstream>

using namespace std;
namespace ama
{
	int Date::mdays(int year, int mon) const
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	Date::Date()
	{
		m_year = 0000;
		m_month = 00;
		m_DotM = 00;
		m_status = no_error;
	}

	Date::Date(int year, int month, int day)
	{
		if (year > max_year || year < min_year)
		{
			*this = Date();
			status(error_year);
		}
		else if (month < 1 || month > 12)
		{
			*this = Date();
			status(error_mon);
		}
		else if (day < 1 || day > mdays(year, month))
		{
			*this = Date();
			status(error_day);
		}
		else
		{
			this->m_year = year;
			this->m_month = month;
			this->m_DotM = day;
			this->m_status = no_error;
			isGood();
		}

		
	}

	int Date::status() const
	{
		return this->m_status;
	}

	void Date::clearError()
	{
		status(no_error);
	}

	bool Date::isGood() const
	{

		if (this->m_status == no_error && !isEmpty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Date::status(int newStatus)
	{
		this->m_status = newStatus;
	}

	bool Date::isEmpty() const
	{
		bool valid;

		if (this->m_year == 0000 && this->m_month == 00 && this->m_DotM == 00)
		{
			valid = true;
		}
		else
		{
			valid = false;
		}

		return valid;

	}

	Date& Date::operator+=(int days)
	{
		int tempday = this->m_DotM;

		if (isGood())
		{
			tempday += days;

			if (tempday > mdays(this->m_year, this->m_month) || tempday < 1)
			{
				status(error_invalid_operation);
			}
			else
			{
				m_DotM += days;
			}
		}
		else
		{
			status(error_invalid_operation);
		}

		return *this;
	}

	Date& Date::operator++()
	{
		int tempday = this->m_DotM;

		if (!isGood())
		{
			status(error_invalid_operation);
		}
		else
		{
			++tempday;
			if (tempday <= mdays(this->m_year, this->m_month))
			{
				this->m_DotM++;
			}
			else
			{
				status(error_invalid_operation);
			}

		}

		return *this;
	}

	Date Date::operator++(int)
	{
		Date temp = *this;
		int copy = this->m_DotM;
		if (!isGood())
		{
			status(error_invalid_operation);
		}

		else
		{
			copy++;
			if (copy <= mdays(this->m_year, this->m_month))
			{
				++(*this);
			}
			else
			{
				status(error_invalid_operation);
			}
		}
		return temp;

	}

	Date Date::operator+(int days) const
	{
		Date copy = *this;
		int tempDays = copy.m_DotM;
		if (!isGood())
		{
			copy.status(error_invalid_operation);
		}
		else
		{
			tempDays = tempDays + days;
			if (tempDays <= mdays(this->m_year, this->m_month))
			{
				copy.m_DotM = copy.m_DotM + days;
			}
			else
			{
				copy.status(error_invalid_operation);
			}
		}
		return copy;
	}

	bool Date::operator==(const Date& rhs) const
	{
		if ((this->m_year == rhs.m_year) && (this->m_month == rhs.m_month) && (this->m_DotM == rhs.m_DotM))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator!=(const Date& rhs) const
	{
		if ((this->m_year != rhs.m_year) || (this->m_month != rhs.m_month) || (this->m_DotM != rhs.m_DotM))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator<(const Date& rhs) const
	{
		if ((this->m_year < rhs.m_year) || (this->m_month < rhs.m_month) || (this->m_DotM < rhs.m_DotM))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator>(const Date& rhs) const
	{
		if ((this->m_year > rhs.m_year) || (this->m_month > rhs.m_month) || (this->m_DotM > rhs.m_DotM))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator<=(const Date& rhs) const
	{
		if ((this->m_year <= rhs.m_year) && (this->m_month <= rhs.m_month) && (this->m_DotM <= rhs.m_DotM))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator>=(const Date& rhs) const
	{
		if ((this->m_year >= rhs.m_year) && (this->m_month >= rhs.m_month) && (this->m_DotM >= rhs.m_DotM))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	std::istream& Date::read(std::istream& istrm)
	{
		int iyear = 0;
		int imonth = 0;
		int iDotM= 0;
		
		char dash = '/';
		istrm >> iyear >> dash >> imonth >> dash >> iDotM;

		if (istrm.fail() == true) 
		{

			*this = Date();
			status(error_input);
		}
		else
		{
			*this = Date(iyear, imonth, iDotM);
		}
			
			return istrm;
	}
	

	std::ostream& Date::write(std::ostream& ostrm) const
	{
		char slash = '/';

		ostrm.fill('0');
		ostrm.width(4);
		ostrm << m_year << slash;

		ostrm.width(2);
		ostrm.unsetf(ios::left);
		ostrm.fill('0');
		ostrm << m_month << slash;

		ostrm.width(2);
		ostrm.unsetf(ios::left);
		ostrm.fill('0');
		ostrm << m_DotM;

		ostrm.fill(' ');

		return ostrm;
	}


	std::istream& operator>>(std::istream& istrm, Date& rhs)
	{
		return rhs.read(istrm);
	}
	std::ostream& operator<<(std::ostream& ostrm, const Date& rhs)
	{
		return rhs.write(ostrm);
	}


}