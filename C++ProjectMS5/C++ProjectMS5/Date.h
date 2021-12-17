#ifndef DATE_H
#define DATE_H
#include <iostream>

namespace ama
{

	const int min_year = 2019;
	const int max_year = 2028;
	const int max_month = 12;
	const int min_month = 1;
	const int max_day = 31;
	const int min_day = 1;
	const int no_error = 0;
	const int error_year = 1;
	const int error_mon = 2;
	const int error_day = 3;
	const int error_invalid_operation = 4;
	const int error_input = 5;

	class Date
	{
		int m_year;
		int m_month;
		int m_DotM;
		int m_status;
		void status(int newStatus);
		int mdays(int year, int mon) const;

	public:

		Date();
		Date(int year, int month, int date);
		int status() const;
		void clearError();
		bool isGood() const;
		bool isEmpty() const;

		Date& operator+=(int days);
		Date& operator++();
		Date operator++(int);
		Date operator+(int days) const;

		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& ostrm) const;

		int getDay() const;
		int getMonth() const;
		int getYear() const;

		
	
		

	};

	std::istream& operator>>(std::istream& istrm, Date& rhs);
	std::ostream& operator<<(std::ostream& ostrm, const Date& rhs);
}

#endif

